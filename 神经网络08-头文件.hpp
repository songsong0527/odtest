//#pragma once
//#include <vector>
//#include <iostream>
//using namespace std;
//
//class Layer
//{
//public:
//	Layer() {};
//	virtual ~Layer() {};
//	virtual vector<float> Forward(vector<float> input) = 0;
//	virtual vector<float> Backward(vector<float> input) = 0;
//	virtual void Update(float lr) = 0;
//
//};
//
//class FullConnect :public Layer {
//	FullConnect(int ninput, int neurenumber) {
//		this->ninput = ninput;
//		this->neurenumber = neurenumber;
//		dw.resize(ninput * neurenumber);
//		db.resize(neurenumber);
//		w.resize(ninput * neurenumber);
//		b.resize(neurenumber);
//		//初始化w和b值
//		for (int i = 0; i < w.size(); i++)
//		{
//			w[i] = rand() % 1000 / 1000.0f;//0~0.1范围
//		}
//		for (int j = 0; j < b.size(); j++)
//		{
//			b[j] = 0;//初始化偏置全为0
//		}
//	}
//	/// <summary>
//	///	输入xi
//	/// </summary>
//	/// <param name="input"></param>
//	/// <returns>返回bi+Σxi*wi</returns>
//	virtual vector<float> Forward(vector<float> input) {
//		y.clear();
//		forwardInput = input;
//		for (int i = 0; i < neurenumber; i++)//外层循环表示返回多少个式子，即神经元个数
//		{
//			float v = 0;
//			for (int j = 0; j < ninput; j++)//内层循环对wi和xi遍历相乘
//			{
//				v += w[i * ninput + j] * input[j];
//			}
//			v += b[i];//获得一个bi+Σxi*wi的值
//			y.push_back(v);
//		}
//		return y;
//	}
//	virtual vector<float> Backward(vector<float> dx) {
//		for (int i = 0; i < neurenumber; i++)
//		{
//			for (int j = 0; j < ninput; j++)
//			{
//				dw[i * ninput + j] += dx[i] * forwardInput[j];
//			}
//			db[i] += dx[i];
//		}
//	}
//	virtual void Update(float lr) {
//		for (int i = 0; i < ninput * neurenumber; ++i)
//		{
//			w[i] += dw[i] * lr;
//		}
//		for (int i = 0; i < ninput; i++)
//		{
//			b[i] += db[i] * lr;
//		}
//		for (int i = 0; i < ninput * neurenumber; ++i)
//		{
//			dw[i] = 0;
//		}
//		for (int i = 0; i < neurenumber; i++)
//		{
//			db[i] = 0;
//		}
//	}
//private:
//	vector<float> dw, db, w, b, y, forwardInput, backwardInput;
//	int ninput, neurenumber;
//};
//
//class Relu :public Layer {
//	virtual vector<float> Forward(vector<float> y) {
//		for (float& yi : y) {
//			yi = yi > 0 ? yi : 0;//Relu激活函数
//		}
//		ys = y;
//		return ys;
//	}
//	virtual vector<float> Backward(vector<float> loss) {
//		vector<float> dx;
//		for (int i = 0; i < loss.size(); i++)
//		{
//			float d = ys[i] > 0 ? 1 : 0;
//			dx.push_back(d * loss[i]);
//		}
//		return dx;
//	}
//	virtual void Update(float lr) {
//
//	}
//private:
//	vector<float> ys, dy;
//};
//
//class Sigmoid