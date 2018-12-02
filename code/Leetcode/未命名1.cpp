#include<iostream>
using namespace std;

//¡‚–ŒºÃ≥–
class A
{
public:
      int _a;
      A(){
      	cout<<"this A()"<<endl;
	  }
	  ~A(){
      	cout<<"this ~A()"<<endl;
	  }
	  A(const A&aaa){
	  	cout<<"this copy A()"<<endl;
	  }
	  
};
class B
{
public:
      int _b;
      B()
      
      	{
      	cout<<"this B()"<<endl;
	  }
	  ~B()
      
      	{
      	cout<<"this ~B()"<<endl;
	  }
	  
};
class C 
{
public:
      int _c;
      C()
      {
      	cout<<"this C()"<<endl;
	  }
	   ~C()
      {
      	cout<<"this ~C()"<<endl;
	  }
};
class D :public B, public C
{
public:
      int _d;
      A aa;
      D(A a1,int dd):_d(dd)
	  {
	  	aa(a1)
	  	cout<<"this D()"<<endl;
	  		cout<<"------"<<endl;
	  };
	   ~D()
      {
      	cout<<"this ~D()"<<endl;
	  }
};
int main()
{
      
      A a;
      D d(a,5);
    	cout<<"-----"<<endl;
     
	
      return 0;
}

