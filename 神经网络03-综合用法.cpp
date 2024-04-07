//#include <vector>
//#include <iostream>
//#include "神经网络03-头文件.hpp"
//#pragma warning(disable:4996)
//using namespace  std;
//
//int main() {
//	//vector<Sample> samples;
//	vector<float> sampleid;
//	vector<float> samplex1;
//	vector<float> samplex2;
//	vector<float> samplex3;
//	vector<float> samplex4;
//	vector<float> samplex5;
//	vector<float> samplex6;
//	vector<float> samplex7;
//	vector<float> samplex8;
//	vector<float> samplex9;
//	vector<float> sampley;
//	float x1;
//	float x2;
//	float x3;
//	float x4;
//	float x5;
//	float x6;
//	float x7;
//	float x8;
//	float x9;
//	float y;
//	float lr = 0.00001f;
//	FILE* fp = fopen("D:\\LocalRepository\\CPPod\\cancer.txt", "r");//以只读模式打开文件
//	while (true)
//	{
//		//Sample sample;
//		int rlen = fscanf(fp, "%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f\r\n", &sampleid, &x1, &x2, &x3, &x4,
//			&x5, &x6, &x7, &x8, &x9, &y);
//		x1 /= 10.0;
//		x2 /= 10.0;
//		x3 /= 10.0;
//		x4 /= 10.0;
//		x5 /= 10.0;
//		x6 /= 10.0;
//		x7 /= 10.0;
//		x8 /= 10.0;
//		x9 /= 10.0;
//		if (y == 2) {
//			y = 0;
//		}
//		else
//		{
//			y = 1;
//		}
//		if (rlen < 3) { break; }
//		samplex1.push_back(x1);
//		samplex2.push_back(x2);
//		samplex3.push_back(x3);
//		samplex4.push_back(x4);
//		samplex5.push_back(x5);
//		samplex6.push_back(x6);
//		samplex7.push_back(x7);
//		samplex8.push_back(x8);
//		samplex9.push_back(x9);
//		sampley.push_back(y);
//	}
//
//	Layer* layer1 = new FullConnect(9, 2);
//	Layer* layer2 = new Sigmoid();
//	Layer* layer3 = new FullConnect(2, 2);
//	Layer* layer4 = new Sigmoid();
//	Layer* layer5 = new FullConnect(2, 1);
//	Layer* layer6 = new Sigmoid();
//
//
//
//	for (int i = 0; i < 1000; i++)
//	{
//		for (int j = 0; j < 100; j++)
//		{
//			vector<float> x = { samplex1[j],samplex2[j], samplex3[j] ,samplex4[j] ,samplex5[j] ,samplex6[j] ,samplex7[j] ,samplex8[j] ,samplex9[j] };
//			//向前传播
//			auto ys = layer1->Forward(x);
//			ys = layer2->Forward(ys);
//			ys = layer3->Forward(ys);
//			ys = layer4->Forward(ys);
//			ys = layer5->Forward(ys);
//			ys = layer6->Forward(ys);//得到了经过两层后的ys值
//			float loss = sampley[j] - ys[0];//loss
//			vector<float> dy = { loss };
//
//			//向后传播
//
//			auto dx = layer6->Backward(dy);
//			dx = layer5->Backward(dx);
//			dx = layer4->Backward(dx);
//			dx = layer3->Backward(dx);
//			dx = layer2->Backward(dx);
//			dx = layer1->Backward(dx);
//
//			layer1->Update(lr);
//			layer3->Update(lr);
//			layer5->Update(lr);
//		}
//	}
//
//	int pass = 0;
//	for (int j = 0; j < 682; j++)
//	{
//		vector<float> test = { samplex1[j],samplex2[j], samplex3[j] ,samplex4[j] ,samplex5[j] ,samplex6[j] ,samplex7[j] ,samplex8[j] ,samplex9[j] };
//		auto ys = layer1->Forward(test);
//		ys = layer2->Forward(ys);
//		ys = layer3->Forward(ys);
//		ys = layer4->Forward(ys);
//		ys = layer5->Forward(ys);
//		ys = layer6->Forward(ys);//得到了经过两层后的ys值
//		if (abs(ys[0] - sampley[j]) <= 0.5) {
//			pass++;
//		}
//	}
//	float rat;
//	rat = pass / 683.0f;   
//	cout << rat << endl;
//}
