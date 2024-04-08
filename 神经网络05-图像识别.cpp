#include "神经网络05-头文件.hpp"
#include <iostream>
#include <vector>
#include <random>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	float lr = 0.001f;
	struct Sample
	{
		int lable; //0-9
		unsigned char pixes[28 * 28];
	};


	FILE* fp = fopen("D:/LocalRepository/CPPod/train68333", "rb");
	vector<Sample> samples;
	samples.resize(68333);
	fread(samples.data(), sizeof(Sample), 68333, fp);
	fclose(fp);


	Layer* layer1 = new FullConnect(28 * 28, 30);
	Layer* layer2 = new ReLu();
	Layer* layer3 = new FullConnect(30, 20);
	Layer* layer4 = new ReLu();
	Layer* layer31 = new FullConnect(20, 10);
	Layer* layer41 = new ReLu();
	Layer* layer5 = new FullConnect(10, 10);
	Layer* layer6 = new Sigmoid();
	vector<float> x;
	vector<float> y;
	int avgcout = 0;
	vector <float> avgdy;

	for (int j = 0; j < 68333; j++)
	{
		for (int idx = 0; idx < 4; idx++)
		{
			int randNumber;
			srand(time(0));
			randNumber = rand() * rand() % 68333;

			//	// 创建一个随机数生成器
			//std::random_device rd;
			//std::mt19937 gen(rd());

			//// 创建一个分布函数，定义随机数的范围
			//std::uniform_int_distribution<> dis(0, 68332);

			//// 生成随机数
			//int randNumber = dis(gen);

			y.clear();
			for (int i = 0; i < 28 * 28; i++)
			{
				float temp = static_cast<float>(samples[randNumber].pixes[i]);
				temp /= 255.0f;
				x.push_back(temp);
			}
			//向前传播
			auto ys = layer1->Forward(x);
			ys = layer2->Forward(ys);
			ys = layer3->Forward(ys);
			ys = layer4->Forward(ys);
			ys = layer31->Forward(ys);
			ys = layer41->Forward(ys);
			ys = layer5->Forward(ys);
			ys = layer6->Forward(ys);
			x.clear();
			for (float i = 0; i < 10; i++)
			{
				if (i == samples[randNumber].lable) {
					y.push_back(1.0f);
				}
				else
				{
					y.push_back(0.0f);
				}
			}
			vector<float> dy;
			float add = 0;
			for (int i = 0; i < 10; i++)
			{
				float loss = (y[i] - ys[i]);
				add += abs(loss);
				dy.push_back(loss < 0 ? loss * 0.1f : loss);
			}
			avgdy.push_back(add);
			avgcout++;
			if (avgcout == 1000) {
				avgcout = 0;
				float sum = 0;
				for (float& avgdyi : avgdy) {
					sum += avgdyi;
				}
				avgdy.clear();
				std::cout << "----------------------------" << endl << sum / 1000 << endl;
			}

			//向后传播

			auto dx = layer6->Backward(dy);
			dx = layer5->Backward(dx);
			dx = layer41->Backward(dx);
			dx = layer31->Backward(dx);
			dx = layer4->Backward(dx);
			dx = layer3->Backward(dx);
			dx = layer2->Backward(dx);
			dx = layer1->Backward(dx);
		}

		layer1->Update(lr);
		layer3->Update(lr);
		layer5->Update(lr);
		layer31->Update(lr);
	}


	FILE* testfp = fopen("D:/LocalRepository/CPPod/test659", "rb");
	vector<Sample> test;
	test.resize(659);
	fread(test.data(), sizeof(Sample), 659, testfp);
	fclose(testfp);
	vector<float> testx;
	int pass = 0;

	for (int j = 0; j < 659; j++)
	{
		testx.clear();
		for (int i = 0; i < 28 * 28; i++)
		{
			float temp = static_cast<float>(test[j].pixes[i]);
			temp /= 255.0f;
			testx.push_back(temp);
		}
		auto yss = layer1->Forward(testx);
		yss = layer2->Forward(yss);
		yss = layer3->Forward(yss);
		yss = layer4->Forward(yss);
		yss = layer5->Forward(yss);
		yss = layer6->Forward(yss);

		auto max = max_element(yss.begin(), yss.end());
		int maxIndex = std::distance(yss.begin(), max);
		if (maxIndex == test[j].lable)
		{
			pass++;
		}
	}
	float rat;
	rat = pass / 659.0f;
	std::cout << rat << endl;
}

//动量参数
//批次量 