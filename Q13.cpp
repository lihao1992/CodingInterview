/* 机器人运动范围 */
// 同样是回溯法，判断矩阵（二维数组）中当前位置是否符合规则，如果符合条件，则继续判断周围相邻四个位置是否同样符合条件，然后再根据题目具体要求，实现下一步的功能

#include<iostream>
#include<vector>

using namespace std;

int sumOfDigit(int num);
bool check(int rows, int cols, int i, int j, int threshold, vector<bool>& visited);
int countNumberCore(int rows, int cols, int i, int j, int threshold, vector<bool> &visited);


// 计算机器人可以走几个格子
int countNumbers(int rows, int cols, int threshold){

    if(rows < 1 || cols < 1 || threshold < 0){
        return 0;
    }

    vector<bool> visited (rows*cols, false);

    int count = 0;
    count = countNumberCore(rows, cols, 0, 0, threshold, visited);

    for(vector<bool>::iterator it = visited.begin(); it != visited.end(); ++it){
        cout << *it << endl;
    }
    return count;
}

int countNumberCore(int rows, int cols, int i, int j, int threshold, vector<bool> &visited){

    int count = 0;

    if(check(rows, cols, i, j, threshold, visited)){

        visited[i*cols + j] = true;

        // 根据具体题目要求去遍历相邻位置，是判断路径还是求相邻位置符合条件的个数
        count = 1 + countNumberCore(rows, cols, i, j-1, threshold, visited)
                    + countNumberCore(rows, cols, i-1, j, threshold, visited)
                    + countNumberCore(rows, cols, i, j+1, threshold, visited)
                    + countNumberCore(rows, cols, i+1, j, threshold, visited);
    }

    return count;
}

bool check(int rows, int cols, int i, int j, int threshold, vector<bool>& visited){

    bool success = false;
    if(i<rows && i>=0 && j<cols && j>=0 && sumOfDigit(i) + sumOfDigit(j) <= threshold && !visited[i*cols + j]){

        success = true;
    }

    return success;
}

int sumOfDigit(int num){

    int sum = 0;
    while(num > 0){

        sum += num%10;
        num /= 10;
    }
    return sum;
}

int main(){

    //cout << countNumbers(5, 5, -1) << endl;
    //cout << countNumbers(5, 5, 8) << endl;
    //cout << countNumbers(5, 5, 0) << endl;
    cout << countNumbers(5, 5, 2) << endl;

    return 0;
}