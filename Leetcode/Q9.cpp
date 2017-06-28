/*判断一个整数是否是回文数*/

#include <iostream>

using namespace std;

// 创建一个数，是原始数字的逆序创建，然后比较这个数和原始数是否相等
bool isPalindromeInteger(int x){

    if(x < 0)
        return false;
    
    if(x == 0)
        return true;
    
    else{

        int tmp = x;
        int res = 0;

        while(tmp > 0){

            res = res*10 + tmp % 10;
            tmp = tmp / 10; 
        }

        if(res == x)
            return true;
        
        else
            return false;
    }

}

int main(){

    int a = 1221;
    int b = 121;
    int c = 123;
    int d = -1;

    isPalindromeInteger(a);
    isPalindromeInteger(b);
    isPalindromeInteger(c);
    isPalindromeInteger(d);

    return 0;
}