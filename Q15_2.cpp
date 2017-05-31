/*给定一个正整数N，求最小的，比N大的正整数M，使得M 与 N的二进制表示中1的个数相同*/

#include<iostream>
#include<vector>

using namespace std;

// 已知可以利用位操作求得n的二进制表示中1的个数，那么可以利用枚举法，从n+1开始比较二进制中1的个数，
// 遇见第一个相等的就停止
int countOf1(int n);
int findNumber(int n){

    int k = countOf1(n);
    do{
        ++n;
    }while(countOf1(n) != k);

    return n;
}

int countOf1(int n){

    int count = 0;
    while(n){
        ++count;
        n = n&(n-1);
    }
    return count;
}

// solution2
// 时间复杂度 O(1)
int solution2(int n){

    int x = n & (-n);
    int t = n + x;
    int result = t | ((n^t)/x)>>2;
    return result;
}

int main(){

    cout << findNumber(1) << endl;
    cout << findNumber(3) << endl;

    cout << solution2(1) << endl;
    cout << solution2(3) << endl;

    return 0;
}