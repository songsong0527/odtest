//#include<iostream>
//
//using namespace std;
//
//class Person {
//public:
//	int m_a;
//	int m_b;
//	//成员函数重载
//	//bool operator==(Person &p) {
//	//	if (m_a == p.m_a && m_b == p.m_b) {
//	//		return true;
//	//	}
//	//	else
//	//	{
//	//		return false;
//	//	}
//	//}
//};
///// <summary>
///// 全局函数重载，要放在定义的类之后
///// </summary>
///// <param name="p1"></param>
///// <param name="p2"></param>
///// <returns></returns>
//bool operator==(Person& p1, Person& p2) {
//	if (p1.m_a == p2.m_a && p1.m_b == p2.m_b) {
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//bool operator!=(Person& p1, Person& p2) {
//	if (p1.m_a != p2.m_a || p1.m_b != p2.m_b) {
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//int main() {
//	Person p1;
//	Person p2;
//	p1.m_a = 20;
//	p1.m_b = 10;
//	p2.m_a = 20;
//	p2.m_b = 10;
//	if (p1 == p2) {
//		cout << "相等" << endl;
//	}
//	else
//	{
//		cout << "不相等" << p2.m_a << endl;
//	}
//	if (p1 != p2) {
//		cout << "不相等" << endl;
//	}
//	else {
//		cout << "相等" << endl;
//	}
//}