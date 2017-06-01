/*数字翻译成字符串*/


#include<iostream>
#include<vector>
#include<string>

using namespace std;

int GetTranslationCount(const string& str);

int GetTranslationCount(int number){
    // '0'翻译成 ‘a’
    if(number < 0)
        return 0;
    
    string str = to_string(number);

    return GetTranslationCount(str);
}

int GetTranslationCount(const string& str){

    int count = 0;
    int len = str.size();

    // 此处vector必须初始化,而且是按照字符串大小初始化，否则会报内存错误！！！
    // 因为是从后向前翻译，所以到counts[0]的时候，存的是整个数组的总的不同翻译数，所以最后输出counts[0]。
    vector<int> counts (len,0);

    // 从后向前翻译并计算不同翻译的数目
    for(int i = len-1; i>=0; --i){

        count = 0;
        if(i < len-1)
            count = counts[i+1];
        
        else
            count = 1;
        
        if(i < len-1){

            int digit1 = str[i]-'0';
            int digit2 = str[i+1]-'0';
            int combine = digit1*10+digit2;

            if(combine >=10 && combine <= 25){

                if(i < len-2)
                    count += counts[i+2];
                else
                    ++count;
            }
        }
        counts[i] = count;
    }

    count = counts[0];

    return count;
}

int main(){

    cout << GetTranslationCount(12258) << endl;
    cout << GetTranslationCount(2) << endl;
    cout << GetTranslationCount(25) << endl;
    cout << GetTranslationCount(0) << endl;
    cout << GetTranslationCount(26) << endl;
    return 0;
}