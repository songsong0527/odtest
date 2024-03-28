//#include <iostream>
//using namespace std;
//
//class Base {
//public:
//	int m_a;
//protected:
//	int m_b;
//private:
//	int m_c;
//};
//class Son :public Base {
//public:
//	int m_d;
//};
//
////利用开发人员提示符工具查看对象模型
////跳转盘符 D:+回车
////CD 文件目录
////dir查看所有文件
////cl /d1 reportSingleClassLayout类名 文件名
//
//int main() {
//	Son son;
//	//父类中的所有非静态成员全部都会被继承
//	cout << sizeof(son) << endl;
//}