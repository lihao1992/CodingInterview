/*1~n整数中1出现的次数*/


#include<iostream>
#include<vector>
#include<string>

using namespace std;

int NumberOf1toN(int n){

    if(n <= 0)
        return 0;
    
    // 将数字转成字符串

    return NumberOf1(str);
}

int NumberOf1(const string& str){

    if(str.empty() || *str < '0' ||*str > '9')
        return 0;
    
    int first = *str - '0';
    int len = str.size();

    if(len == 1 && first == 0)
        return 0;
    
    if(len == 1 && first > 0)
        return 1;
    
    int numFirstDigit = 0;
    if(first > 1)

        numFirstDigit = PowerBase10(len-1);
    
    else if(first == 1)
    
        numFirstDigit = atoi(str+1)+1;
    
    int numOtherDigit = first*(len-1)*PowerBase10(len-2);

    int numRecursive = NumberOf1(str+1);

    return numFirstDigit + numOtherDigit + numRecursive;
}

int PowerBase10(int n){

    int result = 1;
    for(int i = 0; i < n; ++i){

        result *= 10;
    }
    return result;
}