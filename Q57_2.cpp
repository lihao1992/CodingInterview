/*和为s的连续正数序列*/

#include<iostream>

using namespace std;

void printNumber(int small, int big);

void findConsecutiveNumber(int sum){

    if(sum < 3)
        return ;
    
    int small = 1;
    int big = 2;
    int middle = (1+sum) / 2;

    int curSum = small + big;

    while(small < middle){

        if(curSum == sum)
            printNumber(small, big);
        
        while(curSum > sum && small < middle){

            curSum -= small;
            ++small;

            if(curSum == sum)
                printNumber(small, big);
        }

        ++big;
        curSum += big;

    }
}

void printNumber(int small, int big){

    for(int i = small; i <= big; ++i)
        cout << i << ',' ;
    cout << endl;
}

int main(){

    findConsecutiveNumber(15);

    return 0;
}