//#include <iostream>
//using namespace std;
//
//class Person {
//public:
//	Person(int a) {
//		cout << "���ι��캯������" << endl;
//		m_a = new int(a);
//		
//	}
//	Person(Person &p) {
//		cout << "�������캯������" << endl;
//	}
//	~Person() {
//		cout << "������������" << endl;
//		//if (m_a != NULL) {
//		//	delete m_a;
//		//	m_a = NULL;
//		//}
//	}
//	Person& operator=(Person &p) {
//		if (m_a != NULL) {
//			delete m_a;
//		//  m_a = NULL;
//		}
//		this->m_a=new int(*p.m_a);
//		return *this;
//	}
//	int* m_a;//��ŵĵ�ַ
//};
//void test() {
//	Person p1(18);
//	Person p2(20);
//	Person p3(22);
//	p3 = p2 = p1;
//	cout << p2.m_a << endl << p1.m_a << endl << &p2 << endl << &p1 << endl << &p2.m_a << endl << &p1.m_a << endl;
//}
//int main() {
//	test();
//}