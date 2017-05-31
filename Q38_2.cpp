/*字符串的全组合*/

#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

// 假设有元素n个，那么最终的组合结果一共有 2^n-1 个， 可以利用 位操作，设置2^n-1位，
// 1表示取该元素，0表示不取。 所以a就表示为001， ab就是011， ac表示101， c表示为100
// 由位操作，可以引申到Q15，二进制中1的个数；
// 以及Q15_2，给定一个正整数N， 求最小的，比N大的正整数M，使得M与N的二进制中1的个数相同

// 时间复杂度 O(2^N)
void Combination(char *str){

    if(str == nullptr)
        return ;
    
    int len = strlen(str);
    int n = 1<<len;
    //vector<char> result;

    // 从1循环到2^len-1
    for(int i = 0; i < n; ++i){

        vector<char> result;

        for(int j = 0; j < len; ++j){

            if((i & (1<<j)) != 0){

                result.push_back(str[j]);
            }
        }
        for(vector<char>::iterator it = result.begin(); it != result.end(); ++it)
            cout << *it ;
        cout << endl;
    }
}

int main(){

    char str[] = "abc";
    Combination(str);

    return 0;
}