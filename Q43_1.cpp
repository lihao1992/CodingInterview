/*1～n中1出现的次数*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int count(int n){

    if(n<1)
        return 0;
    
    int count = 0;
    int base = 1;
    int round = n;

    while(round > 0){

        int weight = round % 10;
        round /= 10;
        count += round * base;

        if(weight == 1)
            count += (n % base) + 1;
        else if (weight > 1)
            count += base;
        
        base *= 10;
    }
    return count;
}

int main(){

    cout << count(12) << endl;
    cout << count(5) << endl;

    return 0;
}