
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int findLength(string &str){
    
    int curLen = 0;
    int maxLen = 0;

    // 存放每个字符上一次出现在字符串中的位置下标
    vector<int> position (26, -1);  // vector 初始化，用（）, 不是{} ！

    for(int i = 0; i<str.size(); ++i){

        int preIndex = position[str[i]-'a'];    // str[i]上次出现在字符串中的位置，position存的就是下标。
        
        // 如果当前字符在前面没有出现过，或者它之前出现的位置比到目前为止字符串中最长无重复的子字符串长度还要大的时候,那么到第i个字符为止的最长无重复子字符串的长度可以加 1
        if(preIndex < 0 || i - preIndex > curLen){
                
                ++curLen;
        }
        // 如果当前字符出现过，并且又一次出现的位置距离上一次出现的位置的间隔 小于 到目前为止字符串中最长无重复得子字符串的长度， 说明上次出现的位置就在这个子字符串中
        else{
                if(curLen > maxLen)
                    maxLen = curLen;
                
                // 更新当前最长子字符串的长度
                curLen = i-preIndex;
        }
        // 记录当前字符出现的位置下标
        position[str[i]-'a'] = i;
    }

    if(curLen > maxLen)
        maxLen = curLen;
    
    return maxLen;
}

int main(){

    string str = "arabcacfrg";
    string str1 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!";
    string str2 = "aaaaaaaaa";
    string str3 = " ";
    cout << findLength(str) << endl;
    cout << findLength(str1) << endl;
    cout << findLength(str2) << endl;
    cout << findLength(str3) << endl;
    return 0;
}