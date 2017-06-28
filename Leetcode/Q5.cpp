// 最长回文子字符串

#include<iostream>
#include<string>

using namespace std;

// 判断在left,right之间是否存在回文，并且找到一个回文
string findPalindrome(string s, int left, int right){

    int len = s.size();

    while(left >= 0 && right <= len-1 && s[left]==s[right]){

        --left;
        ++right;
    }
    return s.substr(left+1, right-left-1);
}

string findLength(string s){

    //if(s.empty())   return 0;
    if(s.size() <= 1) return s;

    // 定义两个字符串，一个存最长的回文字符串，一个存当前的回文串
    string curLen;
    string maxLen;

    for(int i = 0; i<s.size()-1; ++i){

        curLen =findPalindrome(s, i, i);

        if(curLen.size() > maxLen.size()){
            maxLen = curLen;
        }

        curLen = findPalindrome(s, i, i+1);

        if(curLen.size() > maxLen.size()){
            maxLen = curLen;
        }
    }

    return maxLen;
}

int main(){

    string s1 = "abacdfgfdcaba";
    string s2 = "abacdfgdcaba";
    
    cout << findLength(s1) << endl;
    cout << findLength(s2) << endl;

    return 0;
}