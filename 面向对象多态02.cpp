//#include <iostream>
//using namespace std;
//
//class Base {
//public:
//	virtual void Func() = 0;//纯虚函数
//};
//class Son:public Base {
//public:
//	virtual void Func() {
//		cout << "子类func函数调用" << endl;
//	};
//};
//
//void test01(Base *base) {
//	base->Func();
//	cout <<"指针变量的地址" << &base << endl << "base指针存放的值，应该和传入进来的子类对象的地址相同" << endl << base << endl;
//}
//
//
//int main() {
//	Son son;
//	test01(&son);
//	Base* base1 = new Son;
//	base1->Func();
//	cout <<"父类对象的值，他是一个指针，指向子类对象" << base1 << endl <<"父类对象的地址，指针的地址" << &base1 << endl << "子类对象的地址"<< &son<<endl;
//	delete base1;
//
//
//
//}