

#include<iostream>
#include<string>
#include<vector>

using namespace std;

string findLongestPrefix(vector<string> &str){

    string prefix = " ";
    for(int idx = 0; str.size() > 0; prefix += str[0][idx]){
        
        for(int i = 0; i < str.size(); ++i){

            if(idx >= str[i].size() || (i>0 && str[i][idx]!= str[i-1][idx]))

                return prefix;
        }
    }
    return prefix;
}

int main(){

    vector<string> str = {"leetcode", "leet", "lee", "leetcodes"};

    cout << findLongestPrefix(str) << endl;

    return 0;

}