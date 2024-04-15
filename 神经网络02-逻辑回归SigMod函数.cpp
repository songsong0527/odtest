//#include <iostream>
//#include <vector>
//#pragma warning(disable:4996)
//using namespace std;
//void LogisticRegression();
//int main() {
//
//	LogisticRegression();
//}
//
//void LogisticRegression()
//{
//	// y = a1 * x1 + a2 * x2 + b
//	// y = sigmoid(y)  sigmoid = 1 / (1 + e^(-x))
//
//	struct Sample {
//		float x1, x2, x3, x4, x5, x6, x7, x8, x9;
//		int y;
//	};
//	struct MyID
//	{
//		float id;
//	};
//
//	vector<Sample> samples;
//
//	Sample test;
//	FILE* fp = fopen("D:\\LocalRepository\\CPPod\\cancer.txt", "r");//��ֻ��ģʽ���ļ�
//	while (true)
//	{
//		MyID myId;
//		Sample sample;
//		int rlen = fscanf(fp, "%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%d\r\n", &myId.id, &sample.x1, &sample.x2, &sample.x3, &sample.x4,
//			&sample.x5, &sample.x6, &sample.x7, &sample.x8, &sample.x9, &sample.y);
//		sample.x1 /= 10;
//		sample.x2 /= 10;
//		sample.x3 /= 10;
//		sample.x4 /= 10;
//		sample.x5 /= 10;
//		sample.x6 /= 10;
//		sample.x7 /= 10;
//		sample.x8 /= 10;
//		sample.x9 /= 10;
//		if (sample.y == 2) {
//			sample.y = 0;
//		}
//		else
//		{
//			sample.y = 1;
//		}
//		if (rlen < 11) { break; }
//		samples.push_back(sample);
//	}
//	test = *samples.rbegin();
//	samples.pop_back();
//	fclose(fp);
//	float lr = 0.001;
//	float a1 = rand() % 1000 / 1000.0f;
//	float a2 = rand() % 1000 / 1000.0f;
//	float a3 = rand() % 1000 / 1000.0f;
//	float a4 = rand() % 1000 / 1000.0f;
//	float a5 = rand() % 1000 / 1000.0f;
//	float a6 = rand() % 1000 / 1000.0f;
//	float a7 = rand() % 1000 / 1000.0f;
//	float a8 = rand() % 1000 / 1000.0f;
//	float a9 = rand() % 1000 / 1000.0f;
//	float b = rand() % 1000 / 1000.0f;
//	for (int i = 0; i < 100000; i++)
//	{
//		float da1 = 0;
//		float da2 = 0;
//		float da3 = 0;
//		float da4 = 0;
//		float da5 = 0;
//		float da6 = 0;
//		float da7 = 0;
//		float da8 = 0;
//		float da9 = 0;
//		float db = 0;
//		//��ֹ�ֲ�����
//		for (int j = 0; j < 682; j++)
//		{
//			Sample sample = samples[j];
//			float y = a1 * sample.x1 + a2 * sample.x2 + a3 * sample.x3 + a4 * sample.x4 +
//				a5 * sample.x5 + a6 * sample.x6 + a7 * sample.x7 + a8 * sample.x8 + a9 * sample.x9 + b;
//			float ys = 1.0f / (1.0f + expf(-y));//sigmod����(�����)
//			float loss = sample.y - ys;//��ʧֵ
//			//float dy = (y * (1.0f - y)) * loss;
//			float dy = (ys * (1.0f - ys)) * loss;
//			da1 += sample.x1 * dy;
//			da2 += sample.x2 * dy;
//			da3 += sample.x3 * dy;
//			da4 += sample.x4 * dy;
//			da5 += sample.x5 * dy;
//			da6 += sample.x6 * dy;
//			da7 += sample.x7 * dy;
//			da8 += sample.x8 * dy;
//			da9 += sample.x9 * dy;
//			db += 1 * dy;
//		}
//		a1 += da1 * lr;
//		a2 += da2 * lr;
//		a3 += da3 * lr;
//		a4 += da4 * lr;
//		a5 += da5 * lr;
//		a6 += da6 * lr;
//		a7 += da7 * lr;
//		a8 += da8 * lr;
//		a9 += da9 * lr;
//		b += db * lr;
//	}
//	//Sample test02;
//	//test02 = samples[2];
//	//float y = a1 * test.x1 + a2 * test.x2 + a3 * test.x3 + a4 * test.x4 + a5 * test.x5 + a6 * test.x6
//	//	+ a7 * test.x7 + a8 * test.x8 + a9 * test.x9 + b;//���һ�������������ȷ
//	/*float y = a1 * 0.5 + a2 * 0.4 + a3 * 0.4 + a4 * 0.5 + a5 * 0.7 + a6 * 1.0 + a7 * 0.3 + a8 * 0.2 + a9 * 0.1 + b;*///�ڶ����������������
//	int pass = 0;
//	for (int j = 0; j < 682; j++)
//	{
//		Sample test02;
//		test02 = samples[j];
//		float y = a1 * test02.x1 + a2 * test02.x2 + a3 * test02.x3 + a4 * test02.x4 + a5 * test02.x5 + a6 * test02.x6
//			+ a7 * test02.x7 + a8 * test02.x8 + a9 * test02.x9 + b;
//		float ys = 1.0f / (1.0f + expf(-y));
//	
//		if (abs(ys - test02.y) <= 0.5) {
//			pass++;
//		}
//	}
//	float rat;
//	rat = pass / 682.0f;
//	cout << rat << endl;
//	//system("pause");
//	//for (int i = 0; i < 682; i++)
//	//{
//	//	Sample sample = samples[i];
//	//	if ((sample.x1 == 1 || sample.x2 == 1 || sample.x3 == 1 || sample.x4 == 1 || sample.x5 == 1 ||
//	//		sample.x6 == 1 || sample.x7 == 1 || sample.x8 == 1 || sample.x9 == 1) && sample.y == 0) {
//	//		cout << i << endl;
//	//	}
//	//}  1,6,127,244,479
//
//	system("pause");
//	//https://cloud.tencent.com/developer/article/1694338
//
//}