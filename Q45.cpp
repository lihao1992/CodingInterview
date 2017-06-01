/*将数组排成最小的数*/

// 首先这题是将数组中的数拼接在一起，找到最小的那个组合，那么我们需要注意的是如果数组中的数字是int型的，
// 那么将他们拼接起来，得到的数有可能“溢出”，这就要考虑对拼接数做 大数问题 的处理了。
// 通常将大数问题中的整形数字转换成字符串表示：1.将整形数字转成字符串 （利用string和sstream）

#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

bool compare(const string& str1, const string& str2);

void printMinNumber(vector<int>& nums){

    if(nums.empty())
        return ;

    int len = nums.size();

    //声明一个字符串数组
    string *str = new string[len];

    // 1.将int型转成字符串
    for(int i = 0; i<len; ++i){

        stringstream stream;
        stream << nums[i];
        stream >> str[i];
    }

    sort(str, str+len, compare);

    // 输出根据新比较规则排序后的最小拼接数
    for(int i = 0; i < len; ++i){
        cout << str[i];
    }
    cout << endl;

    delete[] str;
}

// 2. 重新定义了字符串的比较规则 （本题的核心）
bool compare(const string& str1, const string& str2){

    string s1 = str1+str2;
    string s2 = str2+str1;

    return s1<s2;
}

int main(){

    vector<int> nums = {3,1042,321};

    printMinNumber(nums);

    return 0;
}