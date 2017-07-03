#include <iostream>

// 类继承问题
using namespace std;

class A {

    public : 
        int val;
        A() {val = 1;}
};

class B : public A {

    public :
        int val;

        B(int i) {
            val = A::val + i;
        }
};

int main(){

    B b(10);

    cout << b.A::val << endl; // 类B在继承A的时候，没有指名哪种继承，c++默认继承是 私有继承！所以B的对象 不可以访问/使用 基类中公有变量！
                                // 如果想 访问的话， 将继承方式 改为 public
    cout << b.val << endl;

    return 0;
}