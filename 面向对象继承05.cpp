//#include <iostream>
//using namespace std;
////同名静态成员处理
//
//class Base {
//public:
//	//Base() {
//	//	m_a = 10;
//	//	cout << "父类构造函数调用" << endl;
//	//}
//	static	int  m_a;//类内声明
//	static void  fun() {
//		cout << "父类静态成员函数调用" << endl;
//	}
//};
//int Base::m_a = 100;//类外初始化
//
//class Son :public Base {
//public:
//	//Son() {
//	//	m_a = 20;
//	//	cout << "子类构造函数调用" << endl;
//	//}
//	static int  m_a;//类内声明
//	static void  fun() {
//		cout << "子类静态成员函数调用" <<endl;
//	}
//};
//int Son::m_a=200;//类外初始化
///// <summary>
///// 通过对象访问静态成员
///// </summary>
//void test01() {
//	Son son;
//	cout << son.m_a <<endl;
//	cout<<son.Base::m_a<<endl;
//	son.fun();
//	son.Base::fun();
//}
///// <summary>
///// 通过类名访问
///// </summary>
//void test02(){
//	Son::fun();
//	cout<<Son::m_a<<endl;
//	Son::Base::fun();
//	cout << Son::Base::m_a << endl;
//}
//
//int main() {
//	test02();
//}