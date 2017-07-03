#include <iostream>

using namespace std;

class A {

    public :

        A() {}
        ~A() {}

        virtual void foo() = 0; // 纯虚函数
      //  virtual void foo() {} // 虚函数   

};

int main(){

    A aa;
    //aa.foo();

    //return 0;
}
// error: cannot declare variable ‘aa’ to be of abstract type ‘A’
//  because the following virtual functions are pure within ‘A’: virtual void foo() = 0;

// 类中含有纯虚函数， 那么该类不能实例化一个对象 ！