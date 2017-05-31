/*字符串的全排列*/
// 基于递归的思想，将字符串分为两部分，第一个字符和后面所有字符，每次固定第一个字符，求后面字符的排列；然后将第一个字符与后面的字符逐个交换，完成全排列的实现。
// 时间复杂度 O(n!)
#include<iostream>
#include<string>

using namespace std;

void Permutation(char*str, char*begin);
// 字符串的全排列
void Permutation(char* str){

    if(str == nullptr)
        return ;

    Permutation(str, str);

}

void Permutation(char* str, char* begin){

    // begin指向我们当前执行排列操作的字符串的第一个字符
    // 如果begin指向末尾，则打印所有排列
    if(*begin == '\0'){

        cout << str << endl;
    }

    else{

        for(char *ch = begin; *ch != '\0'; ++ch){

            swap(*ch, *begin);
            Permutation(str, begin+1);
            swap(*ch, *begin);
        }
    }
}

int main(){

    char str[] = "abcd";
    Permutation(str);

    return 0;
}