//#include <stdio.h>
//#include <vector>
//#include <stdlib.h>
//#include <time.h>
//#include <iostream>
//
//
//using namespace std;
//int main()
//{
//	//y = 0.5f * x1 + 0.8f * x2 + 1.5 + rand() % 10 / 100.0f
//
//	// y = a * x + b   y = a1 * x1 + a2 + x2 + b
//	// a  b  权重 c 偏置
//
//	//二手手机价格（price）受手机内存大小（brand）和手机使用年限（year）的影响，由此声明下面这个结构体
//	struct Sample
//	{
//		float year;
//		float storage;
//		float price;
//	};
//	//初始化样本
//	//假设价格和年限、内存之间的关系为：pric=20*storage+（-500）*year+1
//	vector<Sample> samples = {
//		{0,128,2561},
//		{2,128,1561},
//		{3,128,1061},
//		{0,256,5121},
//		{1,256,4621},
//		{3,512,8741}   //加上这三个参数后，结果为无穷大
//	};
//
//	//求解方法 《梯度向后传播法》
//
//	float lr = 0.000001f;//学习率
//
//	srand(time(0));
//
//	float a = rand() % 1000 / 100.0f;
//	float b = rand() % 1000 / 100.0f;
//	float c = rand() % 1000 / 100.0f;
//	//y = 0.5f * x1 + 0.8f * x2 + 1.5 + rand() % 10 / 100.0f
//	for (int i = 0; i < 10000000; i++)
//	{
//		int rn = rand() % 6;
//		Sample sample = samples[rn];
//		//float y = a * sample.year + b;
//		float y = a * sample.storage + b * sample.year + c /*+ 1.5 + rand() % 10 / 100.0f*/;
//		//损失值
//		float loss = sample.price - y;
// 
// 
//		////对a求偏导（梯度值）*损失值
//		float da = sample.storage * loss; //d = delta
//		a += da * lr;
//		float db = sample.year * loss;
//		b += db * lr;
//		float dc = 1 * loss;
//	}
//	float price = a * 512 + b * 4 + c;//预测 使用年限4年，内存512g的手机，价格是多少，预测价格是8241
//	cout << price << endl;
//	//线性回归
//	//梯度向后传播法
//
//	return 0;
//}