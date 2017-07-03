// 多重继承中的菱形继承
// class A;  // A 变成了 虚基类 ！
// class B : public virtual A;
// class C : public virtual A;
// class D : public B, public C;  // 类D 同时继承了B和C，B 和 C 又都继承自A，出现了菱形继承情况，因此用到了 虚继承 ！


#include <iostream>
#include <memory.h>
#include <assert.h>

using namespace std;

class A {

    public : 
        void foo() { cout << "A" << endl;}
};

class B {

    public :
        void foo() { cout << "B" << endl;}
};

class C : public A , public B {


};


int main(){

    C c;
    c.A::foo();
    c.B::foo();

    return 0;
}
