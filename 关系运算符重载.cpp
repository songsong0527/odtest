//#include<iostream>
//
//using namespace std;
//
//class Person {
//public:
//	int m_a;
//	int m_b;
//	//��Ա��������
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
///// ȫ�ֺ������أ�Ҫ���ڶ������֮��
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
//		cout << "���" << endl;
//	}
//	else
//	{
//		cout << "�����" << p2.m_a << endl;
//	}
//	if (p1 != p2) {
//		cout << "�����" << endl;
//	}
//	else {
//		cout << "���" << endl;
//	}
//}