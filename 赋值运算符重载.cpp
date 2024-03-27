#include <iostream>
using namespace std;

class Person {
public:
	Person(int a) {
		m_a = new int(a);
	}
	int* m_a;
};
void test() {
	Person p1(20);
	Person p2(18);
	p2 = p1;
	cout << *p2.m_a << endl<<*p1.m_a << endl << &p2 << endl << &p1 << endl << &p2.m_a << endl << &p1.m_a;
}
int main() {
	test();
}