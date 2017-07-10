// 指针与地址
#include <iostream>

using namespace std;

int main(){

    int a[3];
    a[0] = 0, a[1] = 1, a[2] = 2;

    int *p, *q;

    p = a;
    q = &a[2];

    cout << p << endl;
    cout << *p << endl;
    cout << q << endl;
    cout << *q << endl;

    // 地址相减
    cout << a[q-p] << endl;

    cout << a[*q - *p] << endl;

    return 0;
}