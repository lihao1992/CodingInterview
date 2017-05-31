/* 打印从1到最大的N位数 */

#include<iostream>
#include<vector>
#include<string>

using namespace std;

// 当输入的n很大的时候，是不是可能超过了int/long long型能表示的范围？（大数问题）
// 所以必须考虑 大数问题
// 常用的是用字符串 / 数组 表示大数 （选择合适的数组结构 来表示问题）
// 用字符串模拟从1到n位最大数，那么必须模拟加法操作
bool Increment(string &number);
void printNumber(string &number);

void PrintToMax(int n){

    if(n <= 0)   return ;

    string number (n, '0');

    while( !Increment(number)){

        printNumber(number);
    }
}

// 实现在表示数字的字符串上加1的操作 
bool Increment(string &number){

    bool isOverFlow = false;
    int carry = 0;
    int len = number.size();

    for(int i = len-1; i>=0; --i){

        int sum = number[i]-'0'+carry;

        if(i == len-1)
            ++sum;
        
        if(sum >= 10){

            if(i==0)    isOverFlow = true;
            else{
                sum -= 10;
                carry = 1;
                number[i] = '0' + sum;
            }
        }

        else{
            number[i] = '0'+sum;
            break;
        }
    }
    return isOverFlow;
}


void printNumber(string &number){

    // 检查数字字符串开头是不是有多余的’0‘，如果有，那么打印的时候，略过开头的数位’0‘
    bool isBeginning = true;
    int len = number.size();

    for(int i = 0; i<len; ++i){

        if(isBeginning && number[i] != '0')
            isBeginning = false;

        if(!isBeginning){

            cout << number[i] ;
        }
    }
    cout << endl;
}

int main(){

    int k = 2;
    PrintToMax(k);
    PrintToMax(0);
    //PrintToMax(3);
    return 0;
}