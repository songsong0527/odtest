//#include <iostream>
//using namespace std;
//
//class Base {
//public:
//	virtual void Func() = 0;//���麯��
//};
//class Son:public Base {
//public:
//	virtual void Func() {
//		cout << "����func��������" << endl;
//	};
//};
//
//void test01(Base *base) {
//	base->Func();
//	cout <<"ָ������ĵ�ַ" << &base << endl << "baseָ���ŵ�ֵ��Ӧ�úʹ���������������ĵ�ַ��ͬ" << endl << base << endl;
//}
//
//
//int main() {
//	Son son;
//	test01(&son);
//	Base* base1 = new Son;
//	base1->Func();
//	cout <<"��������ֵ������һ��ָ�룬ָ���������" << base1 << endl <<"�������ĵ�ַ��ָ��ĵ�ַ" << &base1 << endl << "�������ĵ�ַ"<< &son<<endl;
//	delete base1;
//
//
//
//}