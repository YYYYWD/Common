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
      //Test(112);            //  构造函数只能在初始化列表中被显示调用，不能在构造函数内部被显示调用
    	
	};
    int &t;
    
};

int main()
{
 Test *p = new Mytest();
 //p->show();
 return 0;
}

