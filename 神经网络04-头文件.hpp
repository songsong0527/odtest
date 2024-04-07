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
//};
//
//class SigMoid :public Layer {
//public:
//	virtual vector<float> Forward(vector<float> input) {
//		output.clear();
//		for (float inputi : input)
//		{
//			float ys = 1.0f / (1.0f + expf(-inputi));//sigmod函数
//			output.push_back(ys);
//		}
//		return output;
//	}
//
//
//	virtual vector<float> Backward(vector<float> input) {
//
//		vector<float> dx;
//		for (int i = 0; i < output.size(); i++)
//		{
//			float d = output[i] * (1.0f - output[i]);//(ys * (1.0f - ys))
//			dx.push_back(input[i] * d);
//		}
//		return dx;
//	}
//
//
//
//	virtual void Update(float lr) {
//
//	}
//private:
//	vector<float> output;
//};
//
////y=x1*w1+x2*w2+b;
//
//class FullConnect :public Layer {
//public:
//	FullConnect(int ninp/*输入个数*/, int n/*神经元个数*/)
//	{
//		this->ninp = ninp;
//		this->n = n;
//		w.resize(ninp * n);
//		b.resize(n);
//		srand(time(0));
//		for (float& wi : w)
//		{
//			wi = rand() % 1000 / 1000.0f;
//		}
//		for (float& bi : b)
//		{
//			bi = 0;
//		}
//	}
//	virtual vector<float> Forward(vector<float> input) {
//		samplex = input;
//		vector<float> y;
//		for (int i = 0; i < n; i++)
//		{
//			float v = 0;
//			for (int j = 0; j < ninp; j++)
//			{
//				v += w[i * ninp + j] * input[j];
//			}
//			v += b[i];
//			y.push_back(v);
//		}
//		output = y;
//		return y;
//	}
//	virtual vector<float> Backward(vector<float> input) {
//
//		vector<float> dx(ninp);
//		dw.resize(ninp * n);
//		db.resize(n);
//		for (int i = 0; i < n; i++)
//		{
//			float v = 0;
//			for (int j = 0; j < ninp; j++)
//			{
//				dx[j] += w[j] * input[i];
//				dw[i * ninp + j] = this->output[i] * input[i];
//			}
//			db[i] += input[i];
//		}
//		return dx;
//	}
//	virtual void Update(float lr) {
//		for (int i = 0; i < b.size(); i++)
//		{
//			b[i] += db[i] * lr;
//		}
//		for (int i = 0; i < w.size(); i++)
//		{
//			w[i] += dw[i] * lr;
//		}
//	}
//
//
//
//
//private:
//	int n;//神经元个数
//	int ninp;//输入个数
//	vector<float> w, b, dw, db, dy, samplex, output;//权重，偏置值
//
//};
