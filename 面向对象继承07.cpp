#include <iostream>

using namespace std;
//¡‚–ŒºÃ≥–

//
class Animal {
public:
	int m_a;
};

class Sheep :public Animal {

};

class Tuo :public Animal {

};

class SheepTuo :public Sheep, public Tuo {
public:
	int m_a;
};

void test01() {
	SheepTuo sheeptuo;
	sheeptuo.Sheep::m_a = 10;
	sheeptuo.Tuo::m_a = 20;
	cout << sheeptuo.Sheep::m_a << endl;
	cout << sheeptuo.Tuo::m_a << endl;
	cout << sheeptuo.m_a << endl;
}
int main() {
	test01();
}
