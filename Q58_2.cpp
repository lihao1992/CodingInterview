/* 左旋字符串 */

#include<iostream>
#include<cstring>

using namespace std;

void Reverse(char *begin, char *end){

    if(begin == nullptr || end == nullptr)
        return  ;
    
    while(begin < end){

        char tmp = *begin;
        *begin = *end;
        *end = tmp;

        ++begin;
        --end;
    }
}

char* rotateString(char *str, int k){

    if(str != nullptr){

        int len = static_cast<int>(strlen(str));
        if(len > 0 && k > 0 && k < len){

            char *firstStart = str;
            char *firstEnd = str+k-1;
            char *sencondStart = str+k;
            char *secondEnd = str+len-1;

            // 将字符串分成两部分，前一部分向后旋转，后一部分向前移
            Reverse(firstStart,firstEnd);

            Reverse(sencondStart,secondEnd);

            Reverse(firstStart, secondEnd);
        }
    }
    return str;
}

int main(){

    char str[] = "google";

    cout << rotateString(str, 3) << endl;

    return 0;
}