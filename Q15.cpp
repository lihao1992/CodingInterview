// 二进制中1的个数

#include<iostream>
#include<vector>

using namespace std;

// n = n&(n-1) 能将n的二进制表示中的最右侧的1翻转成0，只要不停的执行 n&=(n-1)，
// 直到n变为 0 为止，那么 翻转的次数 就是 原数n的二进制中1的个数
int countOf1(int n){

    int count = 0;
    while(n){

        ++count;
        n = n&(n-1);
    }
    return count;
}

int main(){

    cout << countOf1(0x7FFFFFFF) << endl;
    cout << countOf1(9) << endl;
    cout << countOf1(0x80000000) << endl;
    cout << countOf1(0xFFFFFFFF) << endl;

    return 0;
}