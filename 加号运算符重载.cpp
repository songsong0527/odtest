//#include <iostream>
//using namespace std;
////加号运算符重载
//class Person {
//public:
//	Person() {
//		cout << "构造函数调用" << endl;
//	}
//	~Person() {
//		cout << "析构函数调用" << endl;
//	}
//	//Person operator+(Person &p) {
//	//	m_a += p.m_a;
//	//	m_b += p.m_b;
//	//	return *this;
//	//}
//	int m_a;
//	int m_b;
//};
//Person operator+(Person &p1,Person &p2) {
//	Person temp;
//	temp.m_a = p1.m_a + p2.m_a;
//	temp.m_b = p1.m_b + p2.m_b;
//	return temp;
//}
//int main() {
//	Person p1;
//	p1.m_a = 10;
//	p1.m_b = 20;
//	Person p2;
//	p2.m_a = 10;
//	p2.m_b = 20;
//	Person p3;
//	p3 = p1 + p2;
//	cout << p1.m_a << p1.m_b << endl;
//	cout << p3.m_a << p3.m_b << endl;
//}