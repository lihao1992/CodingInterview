/*二维数组的查找*/

#include<iostream>
#include<vector>

using namespace std;
// 从矩阵的最右上角的数开始与target比较，每次可以删掉一行或和一列，这样就可以缩小查找范围
bool findNumber(vector<int>& matrix, int m, int n, int target){

    bool found = false;

    if(matrix.empty() || m<=0 || n<=0)
        return false;
    
    int i = 0;
    int j = n-1;
    while(i<m && j>=0){

        if(matrix[i*n+j] == target){
            found = true;
            break;
        }

        if(matrix[i*n+j] < target){
            ++i;
        }
        else
            --j;
    }

    return found;
}

int main(){

    vector<int> matrix = {1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15};

    cout << findNumber(matrix, 4, 4, 9) << endl;
    //return findNumber(matrix, 4, 4, 7);
    return 0;
}