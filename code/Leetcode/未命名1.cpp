#include<iostream>
using namespace std;

class Test{
public:
    Test(){};
    Test (int x){ /*int_x = x;*/};
    //void show(){cout<< int_x << endl;}

};
int a=8; 
class Mytest:public Test{
public:
    Mytest():t(a) {
      //Test(112);            //  ���캯��ֻ���ڳ�ʼ���б��б���ʾ���ã������ڹ��캯���ڲ�����ʾ����
    	
	};
    int &t;
    
};

int main()
{
 Test *p = new Mytest();
 //p->show();
 return 0;
}

