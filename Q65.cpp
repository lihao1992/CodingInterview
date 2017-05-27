/* 实现加法without四则运算 */

#include<iostream>

using namespace std;

// 位操作
int Add(int num1, int num2){

    int sum, carry;
    do{
        sum = num1^num2;
        carry = (num1 & num2) << 1;
        num1 = sum;
        num2 = carry;
    }
    while(num2 != 0);

    return num1;
}

int main(){

    int num1 = 4, num2 = 6;
    cout << Add(num1, num2) << "," << Add(0,3) << "," << Add(-1, 8);
    cout << endl;
    return 0;
}