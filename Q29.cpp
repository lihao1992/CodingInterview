/*顺时针打印矩阵*/

#include<iostream>
#include<vector>

using namespace std;

void printMatrixCircle(int **numbers, int cols, int rows, int start);
void printNumber(int number);

void printMatrix(int **numbers, int cols, int rows){

    if(numbers == nullptr || cols <= 0 || rows <= 0){
        return ;
    }

    int start = 0;

    while(cols > start*2 && rows > start*2){

        printMatrixCircle(numbers, cols, rows, start);

        ++start;
    }
}

// 实现打印一圈的功能
void printMatrixCircle(int **numbers, int cols, int rows, int start){

    int endX= cols-1-start;
    int endY = rows-1-start;

    // 从左到右打印一行
    for(int i = start; i<=endX; ++i){

        int number = numbers[start][i];
        printNumber(number);
    }

    // 从上到下打印一列, 执行条件是：终止行号必须大于起始行号
    if(start < endY){

        for(int i = start+1; i <= endY; ++i){
            int number = numbers[i][endX];
            printNumber(number);
        }
    }

    // 从右到左打印一行
    if(start < endX && start < endY){

        for(int i = endY-1; i>=start; --i){
            int number = numbers[endY][i];
            printNumber(number);
        }
    }

    // 从下到上打印一列
    if(start < endX && start < endY-1){

        for(int i = endY-1; i>=start+1; --i){
            int number = numbers[i][start];
            printNumber(number);
        }
    }
}

void printNumber(int number){
    cout << number <<endl;
}

int main(){

    int numbers[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    printMatrix(numbers, 4, 4);

    return 0;
}