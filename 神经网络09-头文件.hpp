#include "nvx.h"
#include<iostream>

using namespace n;
using namespace g;
using namespace std;
using namespace v;

struct Sample
{
	int lable;
	string path;
};


vector<Sample> Animal()
{
	//列出文件夹下面的所有文件
	vector<LdItem> allcat = ListDir("D:/animal/Train/0");
	vector<LdItem> alldog = ListDir("D:/animal/Train/1");
	vector<LdItem> allothers = ListDir("D:/animal/Train/2");
	vector<Sample> samples;
	//读取猫片
	for (size_t i = 0; i < allcat.size(); i++)
	{
		Sample sample;
		sample.path = "D:\\animal\\Train\\0\\" + allcat[i].name;
		sample.lable = 0;
		samples.push_back(sample);
	}
	//读取狗片
	for (size_t i = 0; i < alldog.size(); i++)
	{
		Sample sample;
		sample.path = "D:\\animal\\Train\\1\\" + alldog[i].name;
		sample.lable = 1;
		samples.push_back(sample);
	}
	//	读取其他动物片
	for (size_t i = 0; i < allothers.size(); i++)
	{
		Sample sample;
		sample.path = "D:\\animal\\Train\\2\\" + allothers[i].name;
		sample.lable = 2;
		samples.push_back(sample);
	}
	return samples;
}

vector<Sample> AnimalTest() {
	//列出文件夹下面的所有文件
	vector<LdItem> allcat = ListDir("D:/animal/Test/0");
	vector<LdItem> alldog = ListDir("D:/animal/Test/1");
	vector<LdItem> allothers = ListDir("D:/animal/Test/2");
	vector<Sample> samples;
	//读取猫片
	for (size_t i = 0; i < allcat.size(); i++)
	{
		Sample sample;
		sample.path = "D:\\animal\\Test\\0\\" + allcat[i].name;
		sample.lable = 0;
		samples.push_back(sample);
	}
	//读取狗片
	for (size_t i = 0; i < alldog.size(); i++)
	{
		Sample sample;
		sample.path = "D:\\animal\\Test\\1\\" + alldog[i].name;
		sample.lable = 1;
		samples.push_back(sample);
	}
	//	读取其他动物片
	for (size_t i = 0; i < allothers.size(); i++)
	{
		Sample sample;
		sample.path = "D:\\animal\\Test\\2\\" + allothers[i].name;
		sample.lable = 2;
		samples.push_back(sample);
	}
	return samples;

}




void train() {
	//批次值
	int batch = 1;
	//最终输出结果个数
	int finalResult = 3;
	//构建神经图
	Tensor x(batch, 3, 512, 512);//batch,channel,height,width
	Tensor y;
	y = n::Conv(x, 8, 3, 1, 1);//512*512
	y = n::Batchnorm(y);
	y = n::Relu(y);
	y = n::Conv(y, 16, 3, 2, 1);//256*256
	y = n::Relu(y);
	y = n::Conv(y, 32, 3, 2, 1);//128*128
	y = n::Batchnorm(y);
	y = n::Relu(y);
	y = n::Maxpool(y, 2, 2, 0);//64*64

	y = n::Conv(y, 64, 3, 1, 1);//64*64
	y = n::Relu(y);
	y = n::Conv(y, 128, 3, 2, 1);//32*32
	y = n::Batchnorm(y);
	y = n::Relu(y);
	y = n::Maxpool(y, 2, 2, 0);//16*16

	y = n::Conv(y, 256, 3, 1, 1);
	y = n::Batchnorm(y);
	y = n::Relu(y);
	y = n::FullConnect(y, 10);
	y = n::Relu(y);
	y = n::FullConnect(y, finalResult);
	y = n::Sigmoid(y);
	/*y = n::Softmax(y,1);*/

	NeuroGraph graph = SetUp(x, y);
	//优化器，跟超参数相关，（学习率，动量）
	Optimizer opt;
	opt.EnableLearnRate(true, 0.0005f);
	opt.EnableMomentum(true, 0.9f);
	//动态平均值
	RollAvg ravg;
	int i = 0;
	vector<Sample> samples = Animal();
	while (true) {
		i++;
		float loss = 0;
		vector<float> allXdata;
		vector<int> sampleIndex;
		sampleIndex.resize(batch);
		for (int batchi = 0; batchi < batch; batchi++)
		{
			//取一个随机样本
			int rn = Random(0, 14626);
			sampleIndex[batchi] = rn;
			Sample s = samples[rn];
			//图片转张量
			Image image = ReadImage(s.path, 3);
			/*Image image = ReadImage(s.path, 3);*/
			Tensor t = TensorFromImage(image, 3, 512, 512, gsp::NGPU);
			//引用张量数据
			x.refer(t);
			/*x.set(t);*/
			graph.Forward();
			//计算梯度值
			vector<float> Ydata, Grad;
			float AllYdata = 0;
			y.get(Ydata);
			Grad.resize(finalResult * batch);

			for (float& Ydatai : Ydata) {
				AllYdata += Ydatai;
			}

			for (int n = 0; n < batch; n++)
			{
				for (int m = 0; m < finalResult; m++)
				{
					if (m == samples[sampleIndex[n]].lable)
					{
						Grad[n * finalResult + m] = (1.0f - Ydata[n * finalResult + m]);
						printf("%d loss:%f\r", i, Grad[n * finalResult + m]);
					}
					else
					{
						Grad[n * finalResult + m] = (0.0f - Ydata[n * finalResult + m]);
					}
					loss += abs(Grad[m + n * finalResult]);
				}
			}
			//ravg += loss;
			//printf("%d loss:%f\r", i, ravg);
			i++;
			//梯度值复制到输出张量里面
			y.setgrad(Grad);
			//整个神经图向后计算
			graph.Backward();
			//更新参数
			opt.Update(graph.GetWeights());
			//保存模型
			if (i > 0 && i % 1000) {
				SaveGraph(graph, "D:\\model.ng");
			}

			SaveGraph(graph, "D:\\model.ng");
		}

	}
}
void nvxlibtest() {

#pragma region 测试
	NeuroGraph testgraph = LoadGraph("D:\\model.ng");
	Tensor testx = testgraph.GetInputTensor();
	Tensor testy = testgraph.GetOutputTensor();
	int pass = 0;//定义通过样本数
	//读测试样本
	//FILE* testfp = fopen("train68333", "rb");
	vector<Sample> samples = AnimalTest();

	for (int testi = 0; testi < 1500; testi++)
	{
		//取一个随机样本，并归一化
		//int rn = Random(0, 1500);
		Sample sampleTest = samples[testi];
		//图片转张量
		Image image = ReadImage(sampleTest.path, 3);
		/*Image image = ReadImage(s.path, 3);*/
		Tensor t = TensorFromImage(image, 3, 512, 512, gsp::NGPU);
		//重新分配内存
		/*testx.alloc(gDim(1, 3, 512, 512), DType::f32);*/
		//把数据复制到输入张量里面
		testx.refer(t);
		testgraph.Forward();
		//获取预测值
		vector<float> Ydata;
		testy.get(Ydata);
		auto max = max_element(Ydata.begin(), Ydata.end());
		int maxIndex = distance(Ydata.begin(), max);
		if (maxIndex == sampleTest.lable)
		{
			pass++;
		}
		//else
		//{
		//	for (int i = 0; i < 28; ++i) {
		//		for (int j = 0; j < 28; ++j) {
		//			// 计算索引
		//			int index = i * 28 + j;
		//			if (static_cast<int>(sampleTests[testi].pixes[index]) > 128)
		//			{
		//				(sampleTests[testi].pixes[index]) = 1;
		//			}
		//			else
		//			{
		//				(sampleTests[testi].pixes[index]) = 0;
		//			}
		//			// 打印像素值
		//			std::cout << static_cast<int>(sampleTests[testi].pixes[index]) << " ";
		//		}
		//		// 换行
		//		std::cout << std::endl;
		//	}
		//	std::cout << std::endl<< sampleTests[testi].lable<<std::endl<< maxIndex<<std::endl;
		//	
		//	system("pause");
		//	//std::cout << "样本索引：" << testi << "   样本标签：" << sampleTest.lable << std::endl << "-----------------------" << std::endl;
		//}
	}
	float passrat = pass / 1500.0f * 100;
	printf("%f%%\n", passrat);
#pragma endregion
}