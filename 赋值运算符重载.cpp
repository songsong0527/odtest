//#include <iostream>
//using namespace std;
//
//class Person {
//public:
//	Person(int a) {
//		cout << "含参构造函数调用" << endl;
//		m_a = new int(a);
//		
//	}
//	Person(Person &p) {
//		cout << "拷贝构造函数调用" << endl;
//	}
//	~Person() {
//		cout << "析构函数调用" << endl;
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
//	int* m_a;//存放的地址
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