/*斐波那契数列第n项*/

#include<iostream>
#include<vector>

using namespace std;

long long fibonacci(unsigned n){

    // 自下到上的循环实现，先求f(0),f(1),再求f(2),f(3).....f(n)
    vector<int> result = {0,1};

    if(n < 2)   return result[n];
    long long fib1 = 1;
    long long fib2 = 0;
    long long fibN = 0;

    for(int i = 2; i <=n; ++i){

        fibN = fib1 + fib2;
        fib2 = fib1;
        fib1 = fibN;
    }

    return fibN;

}

int main(){

    cout << fibonacci(1000) << endl;
    cout << fibonacci(1) << endl;
    cout << fibonacci(0) << endl;
    cout << fibonacci(3) << endl;
    cout << fibonacci(2) << endl;
    return 0;
}