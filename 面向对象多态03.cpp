//#include <iostream>
//using namespace std;
//
//class AbstractDrinking {
//public:
//	virtual void Boil() = 0;//��ˮ
//	virtual void Brew() = 0;//����
//	virtual void PourWater() = 0;//��ˮ
//	virtual void PutSomething() = 0;//����һЩ����
//};
//
//class Coffee :public AbstractDrinking {
//public:
//	 void Boil() {
//		 cout << "��ũ��ɽȪ" << endl;
//	};//��ˮ
//	 void Brew() {
//		 cout << "���ݿ��ȷ�" << endl;
//	};//����
//	 void PourWater() {
//		 cout << "����С����" << endl;
//	};//��ˮ
//	 void PutSomething() {
//		 cout << "��������" << endl;
//	};//����һЩ����
//};
//
//void test01(AbstractDrinking &base) {
//	base.Boil();
//	base.Brew();
//	base.PourWater();
//	base.PutSomething();
//	cout << "test01�������" <<endl<< &base << endl;
//}
//
//void test02(AbstractDrinking *base) {
//	base->Boil();
//	base->Brew();
//	base->PourWater();
//	base->PutSomething();
//	cout <<"test02�������"<<endl<< base << endl << &base << endl;
//}
//
//
//int main() {
//	Coffee coffee;
//	test01(coffee);
//	test02(&coffee);
//	cout<<"main�����������" <<endl<< &coffee << endl;
//	system("pause");
//}