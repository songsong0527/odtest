#include <iostream>
using namespace std;

class Model
{
public:
	int a = 0;
};

//ǰ�õ���
int operator++(Model& model1) {
	model1.a += 1;
	return model1.a;
}
//���õ���
int operator++(Model& model1,int/*ռλ��*/) {
	int temp = model1.a;
	model1.a++;
	return temp;
}

int main() {
	Model model1;
	cout << ++model1 << endl;

	cout << model1++ << endl;
	
	cout << model1.a << endl;
}