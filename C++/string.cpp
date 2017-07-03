#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int main(){

/*   string s;
    cin >> s;       // 读入string对象， 直到遇到空格为止
    cout << s << endl;

    string s;
    while(getline(cin, s)){ // getline() 输入一整行，直到遇到换行符为止，

        cout << s << endl;
        cout << sizeof(s) << endl;
        cout << s.size() << endl;
        cout << s.length() << endl;
        // cout << strlen(s) << endl;  fault error
    }
    //cout << sizeof(s) << endl;
    */

    string s("value");
    string s2 = s;
    string &p = s;
    cout << sizeof(s) <<endl;
    cout << sizeof(s2) << endl;
    cout << sizeof(int) << endl;
    cout << sizeof(char) << endl;
    cout << sizeof(double) << endl;
    cout << sizeof(string) << endl;
    cout << sizeof(p) << endl;
    p = "hello";
    cout << s << s2 << p << endl;
    
    //将字符串的每个字符换成大写形式
    for(auto &c:s){
        c = toupper(c);
    }
    cout << s << endl;
    return 0;
}