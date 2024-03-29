//#include <iostream>
//
//using namespace std;
//
//class Animal {
//public:
//	//动态多态 关键字virtual 虚函数，地址 晚绑定（在程序运行时确定地址）
//	virtual void  Speak() {
//		cout << "动物在说话"<<endl;
//	}
//};
//class Cat:public Animal {
//public:
//	void Speak() {
//		cout << "小猫在说话" << endl;
//	}
//};
//
//void DoSpeak(Animal &animal) {//父类的引用指向子类对象
//	animal.Speak();
//}
//
//void test01() {
//	Cat cat;
//	DoSpeak(cat);
//}
//int main() {
//	test01();
//}
