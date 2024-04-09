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
//class ReLu :public Layer {
//	virtual vector<float> Forward(vector<float> y) {
//		output.clear();
//
//		for (float yi : y)
//		{
//			float ys = yi > 0 ? yi : 0;//ReLu����
//			output.push_back(ys);
//		}
//		return output;
//	}
//
//	virtual vector<float> Backward(vector<float> dy) {
//		vector<float> dx;
//		for (int i = 0; i < output.size(); i++)
//		{
//			float d = dy[i] > 0 ? 1 : 0;//ReLu��������ֵ
//			dx.push_back(dy[i] * d);
//		}
//		return dx;
//	}
//	virtual void Update(float lr) {
//
//	}
//private:
//	vector<float> output;//ysֵ
//};
//
//
//
//class Sigmoid : public Layer
//{
//public:
//	/// <summary>
//	/// ���ؾ���sigmod�������ysֵ
//	/// </summary>
//	/// <param name="y">float y = a1 * sample.x1 + a2 * sample.x2 + b; </param>
//	/// <returns></returns>
//	virtual vector<float> Forward(vector<float> y)
//	{
//		output.clear();
//		for (float yi : y)
//		{
//			float ys = 1.0f / (1.0f + expf(-yi));//sigmod����
//			output.push_back(ys);
//		}
//		return output;
//	}
//
//	/// <summary>
//	/// ����dyֵ
//	/// </summary>
//	/// <param name="loss">��ʧֵ������yֵ��ȥys</param>
//	/// <returns></returns>
//	virtual vector<float> Backward(vector<float> dy)
//	{
//		vector<float> dx;
//		for (int i = 0; i < output.size(); i++)
//		{
//			float d = output[i] * (1.0f - output[i]);//(ys * (1.0f - ys))
//			dx.push_back(dy[i] * d);
//		}
//		return dx;
//	}
//	virtual void Update(float lr)
//	{
//
//	}
//private:
//	vector<float> output;//ysֵ
//};
//
//
//
///// <summary>
///// 
///// </summary>
//class FullConnect : public Layer
//{
//public:
//	/// <summary>
//	/// ���캯������ʼ��w��b��ֵ��a��b��ֵ��
//	/// </summary>
//	/// <param name="ninp"></param>
//	/// <param name="n"></param>
//	FullConnect(int ninp/*�������*/, int n/*��Ԫ����*/)
//	{
//		w.resize(ninp * n);
//		b.resize(n);
//		this->ninp = ninp;
//		this->n = n;
//		srand(time(0));
//		for (float& wi : w)
//		{
//			wi = rand() % 1000 / 5000.0 - 0.1;
//		}
//		for (float& bi : b)
//		{
//			bi = 0;
//		}
//		dw.resize(ninp * n);
//		db.resize(n);
//	}
//
//
//	virtual vector<float> Forward(vector<float> x)
//	{
//		samplex = x;//��sample�е�xֵ�洢����
//		vector<float> y;
//		for (int i = 0; i < n; i++)
//		{
//			float v = 0;
//			for (int j = 0; j < ninp; j++)
//			{
//				v += w[i * ninp + j] * x[j];
//			}
//			v += b[i];
//			y.push_back(v);
//		}
//		return y;//����float y = w1 * sample.x1 + w2 * sample.x2 +b
//	}
//
//
//	virtual vector<float> Backward(vector<float> dy)
//	{
//		vector<float> dx(ninp);
//		for (int i = 0; i < n; ++i)
//		{
//			float v = 0;
//			for (int j = 0; j < ninp; ++j)
//			{
//				dx[j] += w[i * ninp + j] * dy[i];
//				dw[i * ninp + j] += samplex[j] * dy[i];
//			}
//			db[i] += dy[i];
//		}
//		return dx;
//	}
//
//
//
//	virtual void Update(float lr)
//	{
//		for (int i = 0; i < ninp * n; ++i)
//		{
//			w[i] += dw[i] * lr;
//		}
//		for (int i = 0; i < n; i++)
//		{
//			b[i] += db[i] * lr;
//		}
//		for (int i = 0; i < ninp * n; ++i)
//		{
//			dw[i] = 0;
//		}
//		for (int i = 0; i < n; i++)
//		{
//			db[i] = 0;
//		}
//	}
// 
//private:
//	vector<float> dw, db;
//	vector<float> w, b;
//	vector<float> samplex;
//	int n;
//	int ninp;
//};