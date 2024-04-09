//#include <iostream>
//using namespace std;
////ͬ����̬��Ա����
//
//class Base {
//public:
//	//Base() {
//	//	m_a = 10;
//	//	cout << "���๹�캯������" << endl;
//	//}
//	static	int  m_a;//��������
//	static void  fun() {
//		cout << "���ྲ̬��Ա��������" << endl;
//	}
//};
//int Base::m_a = 100;//�����ʼ��
//
//class Son :public Base {
//public:
//	//Son() {
//	//	m_a = 20;
//	//	cout << "���๹�캯������" << endl;
//	//}
//	static int  m_a;//��������
//	static void  fun() {
//		cout << "���ྲ̬��Ա��������" <<endl;
//	}
//};
//int Son::m_a=200;//�����ʼ��
///// <summary>
///// ͨ��������ʾ�̬��Ա
///// </summary>
//void test01() {
//	Son son;
//	cout << son.m_a <<endl;
//	cout<<son.Base::m_a<<endl;
//	son.fun();
//	son.Base::fun();
//}
///// <summary>
///// ͨ����������
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