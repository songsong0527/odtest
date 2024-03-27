#include <iostream>
using namespace std;

class Model
{
public:
	int a = 0;
};

//前置递增
int operator++(Model& model1) {
	model1.a += 1;
	return model1.a;
}
//后置递增
int operator++(Model& model1,int/*占位符*/) {
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