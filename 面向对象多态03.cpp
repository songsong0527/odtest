//#include <iostream>
//using namespace std;
//
//class AbstractDrinking {
//public:
//	virtual void Boil() = 0;//煮水
//	virtual void Brew() = 0;//冲泡
//	virtual void PourWater() = 0;//倒水
//	virtual void PutSomething() = 0;//放入一些东西
//};
//
//class Coffee :public AbstractDrinking {
//public:
//	 void Boil() {
//		 cout << "煮农夫山泉" << endl;
//	};//煮水
//	 void Brew() {
//		 cout << "冲泡咖啡粉" << endl;
//	};//冲泡
//	 void PourWater() {
//		 cout << "倒入小杯中" << endl;
//	};//倒水
//	 void PutSomething() {
//		 cout << "放入奶油" << endl;
//	};//放入一些东西
//};
//
//void test01(AbstractDrinking &base) {
//	base.Boil();
//	base.Brew();
//	base.PourWater();
//	base.PutSomething();
//	cout << "test01输出内容" <<endl<< &base << endl;
//}
//
//void test02(AbstractDrinking *base) {
//	base->Boil();
//	base->Brew();
//	base->PourWater();
//	base->PutSomething();
//	cout <<"test02输出内容"<<endl<< base << endl << &base << endl;
//}
//
//
//int main() {
//	Coffee coffee;
//	test01(coffee);
//	test02(&coffee);
//	cout<<"main函数输出内容" <<endl<< &coffee << endl;
//	system("pause");
//}