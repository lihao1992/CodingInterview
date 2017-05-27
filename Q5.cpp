/* 替换空格 */

#include<iostream>

using namespace std;

char* replaceBlank(char* str, int n){

    if(str == nullptr || n <= 0)
        return nullptr;
    
    // 计算原字符串长度 和 空格数
    int oldLen = 0;
    int countOfBlank = 0;
    int i = 0;
    while(str[i] != '\0'){

        ++oldLen;

        if(str[i] == ' ')
            ++countOfBlank;
        
        ++i;
    }

    // 将空格替换之后的字符串新长度 
    int newLen = oldLen + countOfBlank*2;
    int left = oldLen;
    int right = newLen;

    while(left >= 0 && right > left){

        if(str[left] == ' '){
            str[right--] = '0';
            str[right--] = '2';
            str[right--] = '%';
        }
        else{
            str[right--] = str[oldLen];
        }
        --oldLen;
    }

    return str;

}

int main(){

    char str[] = "i am lihao";
    cout << replaceBlank(str, 256) << endl;;
    

    return 0;
}