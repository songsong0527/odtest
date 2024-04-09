//#include <vector>
//#include <iostream>
//#include "������04-ͷ�ļ�.hpp"
////#include "ann(1).hpp"
//#pragma warning(disable:4996)
//using namespace  std;
//
//int main() {
//	struct Sample {
//		double x1, x2;
//		double y;
//	};
//	vector<Sample> samples;
//	vector<float> samplex1;
//	vector<float> samplex2;
//	vector<float> sampley;
//	float x1;
//	float x2;
//	float y;
//	float lr = 0.01f;
//	FILE* fp = fopen("D:\\LocalRepository\\CPPod\\studentscore.txt", "r");//��ֻ��ģʽ���ļ�
//	while (true)
//	{
//		Sample sample;
//		int rlen = fscanf(fp, "%f,%f,%f\r\n", &x1, &x2, &y);
//		x1 /= 100.0;
//		x2 /= 100.0;
//		if (rlen < 3) { break; }
//		samplex1.push_back(x1);
//		samplex2.push_back(x2);
//		sampley.push_back(y);
//	}
//
//	Layer* layer1 = new FullConnect(2, 2);
//	Layer* layer2 = new Sigmoid();
//	FullConnect* layer3 = new FullConnect(2, 1);
//	Layer* layer4 = new Sigmoid();
//
//	vector<float> _ys;
//	for (int i = 0; i < 10000; i++)
//	{
//		for (int j = 0; j < 100; j++)
//		{
//			vector<float> x = { samplex1[j],samplex2[j] };
//			//��ǰ����
//			auto ys = layer1->Forward(x);
//			ys = layer2->Forward(ys);
//			ys = layer3->Forward(ys);
//			ys = layer4->Forward(ys);//�õ��˾���������ysֵ
//			_ys.push_back(ys[0]);
//			float loss = sampley[j] - ys[0];//loss
//			vector<float> dy = { loss };
//
//			//��󴫲�
//
//			auto dx = layer4->Backward(dy);
//			dx = layer3->Backward(dx);
//			dx = layer2->Backward(dx);
//			dx = layer1->Backward(dx);
//
//			layer1->Update(lr);
//			layer3->Update(lr);
//		}
//	}
//	int pass = 0;
//	for (int j = 0; j < 100; j++)
//	{
//		vector<float> test = { samplex1[j],samplex2[j] };
//		auto ys = layer1->Forward(test);
//		ys = layer2->Forward(ys);
//		ys = layer3->Forward(ys);
//		ys = layer4->Forward(ys);//�õ��˾���������ysֵ
//		if (abs(ys[0] - sampley[j]) <= 0.5) {
//			pass++;
//		}
//	}
//	float rat;
//	rat = pass / 100.0f;
//	cout << rat << endl;
//}