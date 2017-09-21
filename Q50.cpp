/**/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
string cnt1(string str)
{
    int size = str.size();
    int hash[266] = {0};
    string res = "-1";
    for(int i = 0; i < size; i++)
    {
        hash[str[i]]++;
    }
    for(int i = 0; i < size; i++)
    {
        if(hash[str[i]] == 1)
        {
            res = str[i];
            break;
        }
    }
    return res;
}*/

void findNumber(string str, string res){

    if(str.empty()){

        cout << "invalid input" << endl;
    }

    int hashmap[256] = {0};
    for(int i = 0; i < str.size(); ++i){
        
        hashmap[str[i]]++;
    }

    for(int i = 0; i < str.size(); ++i){

        if( 1 == hashmap[str[i]]){
            cout << "success" << endl;
            res = str[i];
            cout << res << endl;
            break;
        }
    }
    //return "\0";
}

int main(){

    string str = "google";
    string res;
    findNumber(str, res);

    return 0;
}