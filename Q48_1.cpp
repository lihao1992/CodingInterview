#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <memory.h>

using namespace std;  
/*  
int longestSubstringWithNoReapting(string A, int n)   
{  
    int mp[256];  
  
    memset(mp, -1, 256 * sizeof(int));  
  
    int pre = -1, maxSubLen = 0;  
  
    for (int i = 0; i < n; ++i)  
    {  
        pre = max(pre, mp[A[i]]);  
        maxSubLen = max(maxSubLen, i - pre);  
  
        mp[A[i]] = i;  
    }  
  
    return maxSubLen;  
}  */

int longestSubstringWithNoReapting(string str, int length);

int main(void)  
{  
    string str = "aabcdb";  
  
    cout << longestSubstringWithNoReapting(str, str.length())<< endl;  
  
    return 0;  
}


int longestSubstringWithNoReapting(string str, int length){

    if(length < 1)
        return -1;
    
    int dp[256];

    // 给dp数组开辟内存空间，并初始化为-1
    memset(dp, -1, 256*sizeof(int));

    int pre = -1, maxSubStr = 0;

    for(int i = 0; i < n; ++i){

        pre = max(pre, dp[str[i]]);
        maxSubStr = max(maxSubStr, i-pre);

        dp[str[i]] = i;

    }
    return maxSubStr;

}