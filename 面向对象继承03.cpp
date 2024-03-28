//#include<iostream>
//using namespace std;
////继承中构造和析构顺序
//
//class base {
//protected:
//	base() {
//		cout << "父类构造函数调用" << endl;
//	}
//	~base() {
//		cout << "父类析构函数调用" << endl;
//	}
//};
//class son :protected base {
//public:
//	son() {
//		cout << "子类构造" << endl;
//	}
//	~son() {
//		cout << "子类析构" << endl;
//	}
//};
//int main() {
//	son son1;
//}