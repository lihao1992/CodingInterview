/*数值的整数次方 Pow(num, n)*/

#include<iostream>
#include<vector>

using namespace std;

double powerWithUnsignedExp(double num, unsigned int exp);
//设置一个全局变量，判断是否是无效的输入
bool invalid_input = false;

double power(double num, int n){
    
    if(num == 0.0 && n < 0){

        invalid_input = true;
        return 0.0;
    }

    // 如果指数为负数的时候，先对负数取绝对值，然后再计算基数的整数次方，最后取倒数
    unsigned int absExp = (unsigned int) n;
    if(n < 0)
        absExp = (unsigned int)(-n);

    double result = powerWithUnsignedExp(num, absExp);

    if(n < 0)
        result = 1.0 / result;
    
    return result;

}

double powerWithUnsignedExp(double num, unsigned int exp){

    double result = 1.0;
    for(int i = 1; i <= exp; ++i)
        result *= num;
    
    return result;
}

int main(){

    cout << power(2, 3) << endl;
    cout << power(0, -1) << endl;
    cout << power(2, -1) << endl;
    cout << power(-1, 2) << endl;

    return 0;
}