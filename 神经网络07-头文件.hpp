#pragma once
#include "nvx.h"
#include<iostream>

using namespace n;
using namespace g;

void nvxlibtest()
{
	struct Sample
	{
		int lable; //0-9
		unsigned char pixes[28 * 28];
	};
	//#pragma region 模型训练
	//	//批次值
	//	int batch = 2;
	//	//最终输出结果个数
	//	int finalResult = 10;
	//	//构建神经图
	//	Tensor x(batch, 28 * 28);
	//	Tensor y;
	//	y = n::FullConnect(x, 30);
	//	y = n::Relu(y);
	//	y = n::FullConnect(y, 20);
	//	y = n::Relu(y);
	//	y = n::FullConnect(y, finalResult);
	//	y = n::Sigmoid(y);
	//
	//	NeuroGraph graph = SetUp(x, y);
	//
	//
	//	FILE* fp = fopen("train68333", "rb");
	//	vector<Sample> samples;
	//	samples.resize(68333);
	//	fread(samples.data(), sizeof(Sample), 68333, fp);
	//	fclose(fp);
	//	//优化器，跟超参数相关，（学习率，动量）
	//	Optimizer opt;
	//	opt.EnableLearnRate(true, 0.005f);
	//	opt.EnableMomentum(true, 0.9f);
	//
	//	//动态平均值
	//	RollAvg ravg;
	//
	//	for (size_t i = 0; i < 100000; i++)
	//	{
	//		float loss = 0;
	//		vector<float> allXdata;
	//		vector<int> sampleIndex;
	//		sampleIndex.resize(batch);
	//		for (int batchi = 0; batchi < batch; batchi++)
	//		{
	//			//取一个随机样本，并归一化
	//			int rn = Random(0, 68333);
	//			sampleIndex[batchi] = rn;
	//			Sample s = samples[rn];
	//			vector<float> Xdata(28 * 28);
	//			for (size_t idx = 0; idx < 28 * 28; idx++)
	//			{
	//				Xdata[idx] = s.pixes[idx] / 255.0f;
	//			}
	//			allXdata.insert(allXdata.end(), Xdata.begin(), Xdata.end());
	//		}
	//		//把数据复制到输入张量里面
	//		x.set(allXdata);
	//		//整个神经图向前计算
	//		graph.Forward();
	//		//计算梯度值
	//		vector<float> Ydata, Grad;
	//		y.get(Ydata);
	//		Grad.resize(finalResult * batch);
	//		for (int n = 0; n < batch; n++)
	//		{
	//			for (int m = 0; m < finalResult; m++)
	//			{
	//				if (m == samples[sampleIndex[n]].lable)
	//				{
	//					Grad[n * finalResult + m] = 1.0f - Ydata[n * finalResult + m];
	//				}
	//				else
	//				{
	//					Grad[n * finalResult + m] = 0.0f - Ydata[n * finalResult + m];
	//				}
	//				loss += abs(Grad[n]);
	//			}
	//		}
	//		ravg += loss;
	//		printf("%d/100000 loss:%f\r", i, (float)ravg);
	//		//梯度值复制到输出张量里面
	//		y.setgrad(Grad);
	//		//整个神经图向后计算
	//		graph.Backward();
	//
	//
	//		//更新参数
	//		opt.Update(graph.GetWeights());
	//
	//		//保存模型
	//		if (i > 0 && i % 1000) {
	//			SaveGraph(graph, "D:\\model.ng");
	//		}
	//	}
	//	SaveGraph(graph, "D:\\model.ng");
	//#pragma endregion

#pragma region 测试
	NeuroGraph testgraph = LoadGraph("D:\\model.ng");
	Tensor testx = testgraph.GetInputTensor();
	Tensor testy = testgraph.GetOutputTensor();
	int pass = 0;//定义通过样本数
	//读测试样本
	FILE* testfp = fopen("train68333", "rb");
	vector<Sample> sampleTests;
	sampleTests.resize(68333);
	fread(sampleTests.data(), sizeof(Sample), 68333, testfp);
	fclose(testfp);
	for (int testi = 0; testi < 68333; testi++)
	{
		////取一个随机样本，并归一化
		//int rn = Random(0, 659);
		Sample sampleTest = sampleTests[testi];
		vector<float> Xdata(28 * 28);
		for (int idx = 0; idx < 28 * 28; idx++)
		{
			Xdata[idx] = sampleTest.pixes[idx] / 255.0f;
		}
		//重新分配内存
		testx.alloc(gDim(1, 28 * 28), DType::f32);
		//把数据复制到输入张量里面
		testx.set(Xdata);
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




	float passrat = pass / 68333.0f * 100;
	printf("%f%%\n", passrat);
#pragma endregion
}


