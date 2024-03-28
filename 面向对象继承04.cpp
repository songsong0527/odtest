//#include<iostream>
//using namespace std;
////同名非静态成员处理
//class Base {
//public:
//	Base() {
//		m_a = 100;
//	}
//	void fun() {
//		cout << "父类函数调用" << endl;
//	}
//	void fun(int a) {
//		cout << a <<endl;
//	}
//	int m_a;
//};
//
//class Son :public Base {
//public:
//	Son() {
//		m_a = 200;
//	}
//	void fun() {
//		cout << "子类函数调用" << endl;
//	}
//	int m_a;
//};
//
//void test01() {
//	Son son;
//	cout <<"son" << son.m_a << endl;
//	cout << "base" << son.Base::m_a << endl;//通过子类对象访问父类的同名属性，加上作用域Base::即可
//	son.fun();
//	son.Base::fun();//通过子类的对象访问父类同名函数
//	son.Base::fun(100);
//	//son.fun(100);子类中如果存在父类的同名成员函数，子类将隐藏所有父类的同名成员函数，需要加入作用域才能访问。
//	//若删除了子类的同名成员函数，则可以直接访问。
//}
//
//int main() {
//	test01();
//}