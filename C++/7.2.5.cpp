// 内存偏移的理解

#include <iostream>

using namespace std;

class A{

    public:

        A(){ m_a = 1; m_b = 2;}

        ~A() {}

        void fun(){
            cout << m_a << m_b << endl;
        }
    
    private:

        int m_a;
        int m_b;
};

class B{

    public:

        B() {m_c = 3;}
        ~B() {}

        void fun(){ cout << m_c << endl;}
    
    private:
        int m_c;
};

int main(){

    A a;
    B *pb = (B*)(&a);

    cout << &a << endl;
    cout << &(a.m_a) << endl;
  /*  cout << &(A::m_a) << endl;
    cout << &(A::m_b) << endl;
    cout << &(B::m_c) << endl; */

    pb->fun();

    return 0;
}