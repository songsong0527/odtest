//#include<iostream>
//using namespace std;
////ͬ���Ǿ�̬��Ա����
//class Base {
//public:
//	Base() {
//		m_a = 100;
//	}
//	void fun() {
//		cout << "���ຯ������" << endl;
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
//		cout << "���ຯ������" << endl;
//	}
//	int m_a;
//};
//
//void test01() {
//	Son son;
//	cout <<"son" << son.m_a << endl;
//	cout << "base" << son.Base::m_a << endl;//ͨ�����������ʸ����ͬ�����ԣ�����������Base::����
//	son.fun();
//	son.Base::fun();//ͨ������Ķ�����ʸ���ͬ������
//	son.Base::fun(100);
//	//son.fun(100);������������ڸ����ͬ����Ա���������ཫ�������и����ͬ����Ա��������Ҫ������������ܷ��ʡ�
//	//��ɾ���������ͬ����Ա�����������ֱ�ӷ��ʡ�
//}
//
//int main() {
//	test01();
//}