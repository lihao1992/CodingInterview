#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <assert.h>

using namespace std;

// 虚继承 类的大小 / 直接继承 类的大小
class A{

    char k[3];

    public:

        virtual void aa(){};
};

class B: public virtual A{

    char j[3];

    public:

        virtual void bb(){};
};

class C: public virtual B{

    char i[3];

    public:

        virtual void cc() {};

};

int main(){

    cout << "size of A :" << sizeof(A) << endl;

    cout << "size of B :" << sizeof(B) << endl;

    cout << "size of C :" << sizeof(C) << endl;

    return 0;
}

//