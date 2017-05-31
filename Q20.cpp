/*判断字符串是否表示数值*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool scanUnsignedInteger(&str);
bool scanInteger(&str);

bool isNumeric(string &str){

    if(str.empty())
        return false;
    
    bool numeric = scanInteger(str);

    if(*str == '.'){

        ++str;
        numeric = scanUnsignedInteger(str) || numeric;
    }

    if(*str == 'e' || 'E'){

        ++str;
        numeric = scanInteger(str);
    }

    return numeric && *str == '\0';
}

bool scanInteger(&str){

    if(*str == '+' || *str == '-')
        ++str;
    
    return scanUnsignedInteger(str);
}

bool scanUnsignedInteger(&str){

    const char* before = *str;
    while(*str != '\0' && *str >= '0' && *str <= '9')
        ++str;
    
    return *str > *before;
}


int main(){

    string str = "123.456";

    return isNumeric(str)；
    
}