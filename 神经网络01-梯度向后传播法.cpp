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
//	// a  b  Ȩ�� c ƫ��
//
//	//�����ֻ��۸�price�����ֻ��ڴ��С��brand�����ֻ�ʹ�����ޣ�year����Ӱ�죬�ɴ�������������ṹ��
//	struct Sample
//	{
//		float year;
//		float storage;
//		float price;
//	};
//	//��ʼ������
//	//����۸�����ޡ��ڴ�֮��Ĺ�ϵΪ��pric=20*storage+��-500��*year+1
//	vector<Sample> samples = {
//		{0,128,2561},
//		{2,128,1561},
//		{3,128,1061},
//		{0,256,5121},
//		{1,256,4621},
//		{3,512,8741}   //���������������󣬽��Ϊ�����
//	};
//
//	//��ⷽ�� ���ݶ���󴫲�����
//
//	float lr = 0.000001f;//ѧϰ��
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
//		//��ʧֵ
//		float loss = sample.price - y;
// 
// 
//		////��a��ƫ�����ݶ�ֵ��*��ʧֵ
//		float da = sample.storage * loss; //d = delta
//		a += da * lr;
//		float db = sample.year * loss;
//		b += db * lr;
//		float dc = 1 * loss;
//	}
//	float price = a * 512 + b * 4 + c;//Ԥ�� ʹ������4�꣬�ڴ�512g���ֻ����۸��Ƕ��٣�Ԥ��۸���8241
//	cout << price << endl;
//	//���Իع�
//	//�ݶ���󴫲���
//
//	return 0;
//}