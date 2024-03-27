//#include <iostream>
//using namespace std;
//
//
//class Person {
//	friend ostream& operator<<(ostream& cout, Person& p);//友元
//public:
//	Person(int a,int b) {
//		this->m_a = a;
//		this->m_b = b;
//	}
//private:
//	int m_a;
//	int m_b;
//};
///// <summary>
///// 左移运算符重定义
///// </summary>
///// <param name="cout"></param>
///// <param name="p"></param>
///// <returns></returns>
//ostream& operator<<(ostream &cout,Person &p) {
//	cout<<p.m_a<<p.m_b;
//	return cout;
//}
//void test01(Person &p) {
//	cout << p << endl;
//}
//int main() {
//	Person p1(10,20);
//	cout <<p1<<endl;
//	test01(p1);
//}