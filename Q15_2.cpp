/*给定一个正整数N，求最小的，比N大的正整数M，使得M 与 N的二进制表示中1的个数相同*/

#include<iostream>
#include<vector>

using namespace std;

// 已知可以利用位操作求得n的二进制表示中1的个数，那么可以利用枚举法，从n+1开始比较二进制中1的个数，
// 遇见第一个相等的就停止
int countOf1(int n);
int findNumber(int n){

    int k = countOf1(n);
    do{
        ++n;
    }while(countOf1(n) != k);

    return n;
}

int countOf1(int n){

    int count = 0;
    while(n){
        ++count;
        n = n&(n-1);
    }
    return count;
}

// solution2
// 时间复杂度 O(1)
int solution2(int n){

// x是求得最右边的第一个1的位置，
// n+x是相当于在最右边的那一堆1中加1，那么就会得到最右边那一堆1的左侧的进位，
// n^t是相当于在整个n的二进制表示中，排除掉前面那些不相干的数堆1，只留下最后一堆1，然后 (n^t)/x
// 相当于将最后那堆1整体挪到整个数的末尾位置，然后在右移2位，相当于抛弃到两个1，
// 最后 t | ((n^t)/x)>>2 将前面那数堆1再补上，得到完整的结果。 
    int x = n & (-n);
    int t = n + x;
    int result = t | ((n^t)/x)>>2;
    return result;
}



int main(){

    cout << findNumber(1) << endl;
    cout << findNumber(3) << endl;

    cout << solution2(1) << endl;
    cout << solution2(3) << endl;

    return 0;
}