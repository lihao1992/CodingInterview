/*计算矩阵相乘*/
// 常用优化方法 内层两个循环，颠倒顺序

#include <iostream>
#include <vector>

using namespace std;

void matrixMultiply(vector<vector<int> >& matrixA, int m, int k, int n, vector<vector<int> >& matrixB, vector<vector<int> >& matrixRes){

 /* if(matrixA.empty() || matrixB.empty())
        return ; */
    
    for(int i=0; i<m; ++i){

        for(int j = 0; j < n; ++j){

           // matrixRes[i][j] = 0;
            for(int t = 0; t < k; ++k){

                matrixRes[i][j] += matrixA[i][t] * matrixB[t][j];
            }
        }
    }
    
}

int main(){

    // vector<vector <int> > ivec(m ,vector<int>(n,0)); //m*n的二维vector，所有元素初始化为0
    // vector<vector<int> > matrix
    // int row=matrix.size();//行数
    // int collor=matrix[0].size();//列数
    vector<vector<int> > matrixA = { {2,2},{2,2} };   // m*k
    vector<vector<int> > matrixB = { {1,0},{0,1} };   // k*n

    int m = matrixA.size();
    int n = matrixB[0].size();
    int k = matrixB.size();

    cout << "row of A:" << m << endl;
    cout << "col of B:" << n << endl;
    cout << "row of B:" << k << endl;

    for(int i = 0; i< matrixA.size(); ++i){
        for(int j = 0; j < matrixA[0].size(); ++j)

            cout << matrixA[i][j] << ",";
        
        cout << endl;
    }

    for(int i = 0; i< matrixB.size(); ++i){
        for(int j = 0; j < matrixB[0].size(); ++j)

            cout << matrixB[i][j] << ",";
        
        cout << endl;
    }

    vector<vector<int> > matrixResult (m, vector<int>(n,0)); // m*n
    for(int i = 0; i< matrixResult.size(); ++i){
        for(int j = 0; j < matrixResult[0].size(); ++j)

            cout << matrixResult[i][j] << ",";
        
        cout << endl;
    }


    matrixMultiply(matrixA, m, k, n, matrixB, matrixResult);


    for(int i = 0; i< matrixResult.size(); ++i){
        for(int j = 0; j < matrixResult[0].size(); ++j)

            cout << matrixResult[i][j] << ",";
        
        cout << endl;
    }

    return 0;
}