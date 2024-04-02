#include <vector>
using namespace std;

class Layer
{
public:
	Layer() {};
	virtual ~Layer() {};
	virtual vector<float> Forward(vector<float> input) = 0;
	virtual vector<float> Backward(vector<float> input) = 0;
	virtual void Update(float lr) = 0;

};


class Sigmoid : public Layer
{
public:
	/// <summary>
	/// ���ؾ���sigmod�������ysֵ
	/// </summary>
	/// <param name="y">float y = a1 * sample.x1 + a2 * sample.x2 + b; </param>
	/// <returns></returns>
	virtual vector<float> Forward(vector<float> y)
	{
		output.clear();
		for (float yi : y)
		{
			float ys = 1.0f / (1.0f + expf(-yi));//sigmod����
			output.push_back(ys);
		}
		return output;//��������ysֵ
	}
	/// <summary>
	/// ����dyֵ
	/// </summary>
	/// <param name="loss">��ʧֵ������yֵ��ȥys</param>
	/// <returns></returns>
	virtual vector<float> Backward(vector<float> dy)
	{
		vector<float> dx;
		for (int i = 0; i < output.size(); ++i)
		{
			float d = output[i] * (1.0f - output[i]);//(ys * (1.0f - ys))
			dx.push_back(dy[i] * d);
		}
		return dx;
	}
	virtual void Update(float lr)
	{

	}
private:
	vector<float> output;//ysֵ
};



/// <summary>
/// 
/// </summary>
class FullConnect : public Layer
{
public:
	/// <summary>
	/// ���캯������ʼ��w��b��ֵ��a��b��ֵ��
	/// </summary>
	/// <param name="ninp"></param>
	/// <param name="n"></param>
	FullConnect(int ninp/*�������*/, int n/*��Ԫ����*/)
	{
		lr = 0.0001;
		w.resize(ninp * n);
		b.resize(n);
		this->ninp = ninp;
		this->n = n;

		for (float& wi : w)
		{
			wi = rand() % 1000 / 1000.0f;
		}
		for (float& bi : b)
		{
			bi = 0;
		}
	}

	virtual vector<float> Forward(vector<float> x)
	{
		samplex = x;//��sample�е�xֵ�洢����
		vector<float> y;
		for (int i = 0; i < n; i++)
		{
			float v = 0;
			for (int j = 0; j < ninp; j++)
			{
				v += w[i * ninp + j] * x[j];
			}
			v += b[i];
			y.push_back(v);
		}
		return y;//����float y = w1 * sample.x1 + w2 * sample.x2 +b
	}

	virtual vector<float> Backward(vector<float> dy)
	{
		vector<float> dx;
		for (int i = 0; i < ninp  ; i++)
		{
			dx.push_back(w[i] * dy[0]);
			w[i] += samplex[i] * dy[0];
		}
		return dx;
	}

	virtual void Update(float lr)
	{
		for (float& wi : w) {
			wi += wi * lr;
		}
	}

private:

	vector<float> w, b;
	vector<float> samplex;
	int n;
	int ninp;
	int lr;
};


//void ANN()
//{
//
//	Layer* layer1 = new FullConnect(2, 2);
//	Layer* layer2 = new Sigmoid();
//	Layer* layer3 = new FullConnect(2, 1);
//	Layer* layer4 = new Sigmoid();
//
//
//	for (size_t i = 0; i < 10000; i++)
//	{
//		vector<float> x = { 0.6, 0.7 };
//		auto r = layer1->Forward(x);
//		r = layer2->Forward(r);
//		r = layer3->Forward(r);
//		r = layer4->Forward(r);//���ݺ�õ���ysֵ
//
//		//loss=����yֵ��ȥys
//		float loss = 1 - r[0];
//
//		vector<float> dy = { loss };
//
//		auto dx = layer4->Backward(dy);
//		dx = layer3->Backward(dx);
//		dx = layer2->Backward(dx);
//		dx = layer1->Backward(dx);
//
//
//
//		layer1->Update();
//		//...
//	}
//}