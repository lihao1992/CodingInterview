//传递动态内存

#include <iostream>
#include <cstring>

using namespace std;

/*
void GetMemory(char* p, int num){

    p = (char*)malloc(sizeof(char) * num);
}

int main(){

    char *str = nullptr;

    GetMemory(str, 100);

    strcpy(str, "hello");

    return 0;
}
*/

/*
// 指向指针的指针
void GetMemory(char** p, int num){

    *p = (char*)malloc(sizeof(char) * num);
}

int main(){

    char *str = nullptr;

    GetMemory(&str, 100);

    strcpy(str, "hello");

    cout << *str << endl; // 字符串首某一字符
    cout << str << endl;  // 字符串
    cout << &str << endl; // 字符串地址

    return 0;
}
*/

// 有函数返回值的
char* GetMemory(char* p, int num){

    p = (char*)malloc(sizeof(char) * num);
    
    return p;
}

int main(){

    char* str = nullptr;

    str = GetMemory(str, 100);

    strcpy(str, "lihao");

    cout << str << endl;

    return 0;
}