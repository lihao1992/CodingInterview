

#include<iostream>
#include<vector>

using namespace std;

void Reverse(char* start, char* end);

char* reverseString(char *s){

    if(s == nullptr)
        return nullptr;
    
    // 找到字符串结尾
    char* start = s;
    char* end = s;

    while(*end != '\0') ++end;
    
    --end;

    Reverse(start, end);

    start = end = s;

    while(*start != '\0'){

        if(*start == ' '){

            ++start;
            ++end;
        }
        else if(*end == ' ' || *end == '\0'){

            --end;
            Reverse(start, end);
            start = ++end;
        }
        else
            ++end;
    }
    return s;
}

void Reverse(char* start, char* end){

    if(start == nullptr || end == nullptr)
        return ;
    
    while(start < end){

        char tmp = *start;
        *start = *end;
        *end = tmp;

        ++start;
        --end;
    }
}

int main(){

    char s[] = "  i am lihao.";
    
    cout << reverseString(s) << endl;

    return 0;
}