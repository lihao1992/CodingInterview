/* 回溯法 */
/*矩阵中的路径*/
/*
#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool hasPathCore(const string& matrix, int rows, int cols, int i, int j, const string& str, int& pathLen, vector<bool>& visited);

bool hasPath(string& matrix, int rows, int cols, string& str){

    // 边界条件
    if(matrix.empty() || rows < 1 || cols > 1 || str.empty()){

        return false;
    }

    // 设置标记位，标记矩阵中的某个位置是否已经访问过
    vector<bool> visited (rows*cols, false);

    // 标记目标字符串当前位置
    int pathLen = 0;

    for(int i = 0; i < rows; ++i){

        for(int j = 0; j < cols; ++j){

            if(hasPathCore(matrix, rows, cols, i, j, str, pathLen, visited))

                return true;
        }
    }

    return false;
}

bool hasPathCore(const string& matrix, int rows, int cols, int i, int j, const string& str, int& pathLen, vector<bool>& visited){

    if(str[pathLen] == '\0')
        return true;

    bool hasPath = false;
    
    // 当满足边界条件， 并且 矩阵中当前位置 与 目标字符串当前字符 相等； 并且矩阵中当前位置没有被访问过 
    if(i >= 0 && i < rows && j >= 0 && j < cols && matrix[i*cols + j] == str[pathLen] && !visited[i*cols + j]){

        ++pathLen;
        visited[i*cols + j] = true;

        // 从矩阵中当前位置的四个方向的相邻位置查找目标字符串的下一个字符
        hasPath = hasPathCore(matrix, rows, cols, i, j-1, str, pathLen, visited) ||
                    hasPathCore(matrix, rows, cols, i-1, j, str, pathLen, visited) ||
                    hasPathCore(matrix, rows, cols, i, j+1, str, pathLen, visited) ||
                    hasPathCore(matrix, rows, cols, i+1, j, str, pathLen, visited);
        
        // 如果相邻的四个位置都没有匹配到目标字符串的下一个字符， 那么矩阵中当前位置的值不是我们想要的，所以返回上一位置，重新查找
        if( !hasPath ){
            
            --pathLen;
            visited[i*cols + j] = false;
        }
    }
    return hasPath;
}

int main(){

    string matrix = "abtgcfcsjdeh";
    string target = "bfce";

    if(hasPath(matrix, 3, 4, target)){

        cout << "exist current target in this matrix ！" << endl;
    }
    else 
        cout << "not exist " << endl;

    
    return 0;
}
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

bool hasPathCore(const char* matrix, int rows, int cols, int row, int col, const char* str, int& pathLength, bool* visited);

bool hasPath(const char* matrix, int rows, int cols, const char* str)
{
    if(matrix == nullptr || rows < 1 || cols < 1 || str == nullptr)
        return false;

    bool *visited = new bool[rows * cols];
    memset(visited, 0, rows * cols);

    int pathLength = 0;
    for(int row = 0; row < rows; ++row)
    {
        for(int col = 0; col < cols; ++col)
        {
            if(hasPathCore(matrix, rows, cols, row, col, str,
                pathLength, visited))
            {
                return true;
            }
        }
    }

    delete[] visited;

    return false;
}

bool hasPathCore(const char* matrix, int rows, int cols, int row,
    int col, const char* str, int& pathLength, bool* visited)
{
    if(str[pathLength] == '\0')
        return true;

    bool hasPath = false;
    if(row >= 0 && row < rows && col >= 0 && col < cols
        && matrix[row * cols + col] == str[pathLength]
        && !visited[row * cols + col])
    {
        ++pathLength;
        visited[row * cols + col] = true;

        hasPath = hasPathCore(matrix, rows, cols, row, col - 1,
            str, pathLength, visited)
            || hasPathCore(matrix, rows, cols, row - 1, col,
                str, pathLength, visited)
            || hasPathCore(matrix, rows, cols, row, col + 1,
                str, pathLength, visited)
            || hasPathCore(matrix, rows, cols, row + 1, col,
                str, pathLength, visited);

        if(!hasPath)
        {
            --pathLength;
            visited[row * cols + col] = false;
        }
    }

    return hasPath;
}

// ====================测试代码====================
void Test(const char* testName, const char* matrix, int rows, int cols, const char* str, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(hasPath(matrix, rows, cols, str) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

//ABTG
//CFCS
//JDEH

//BFCE
void Test1()
{
    const char* matrix = "ABTGCFCSJDEH";
    const char* str = "BFCE";

    Test("Test1", (const char*) matrix, 3, 4, str, true);
}

//ABCE
//SFCS
//ADEE

//SEE
void Test2()
{
    const char* matrix = "ABCESFCSADEE";
    const char* str = "SEE";

    Test("Test2", (const char*) matrix, 3, 4, str, true);
}

//ABTG
//CFCS
//JDEH

//ABFB
void Test3()
{
    const char* matrix = "ABTGCFCSJDEH";
    const char* str = "ABFB";

    Test("Test3", (const char*) matrix, 3, 4, str, false);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SLHECCEIDEJFGGFIE
void Test4()
{
    const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SLHECCEIDEJFGGFIE";

    Test("Test4", (const char*) matrix, 5, 8, str, true);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEHJIGQEM
void Test5()
{
    const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SGGFIECVAASABCEHJIGQEM";

    Test("Test5", (const char*) matrix, 5, 8, str, true);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEEJIGOEM
void Test6()
{
    const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SGGFIECVAASABCEEJIGOEM";

    Test("Test6", (const char*) matrix, 5, 8, str, false);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEHJIGQEMS
void Test7()
{
    const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SGGFIECVAASABCEHJIGQEMS";

    Test("Test7", (const char*) matrix, 5, 8, str, false);
}

//AAAA
//AAAA
//AAAA

//AAAAAAAAAAAA
void Test8()
{
    const char* matrix = "AAAAAAAAAAAA";
    const char* str = "AAAAAAAAAAAA";

    Test("Test8", (const char*) matrix, 3, 4, str, true);
}

//AAAA
//AAAA
//AAAA

//AAAAAAAAAAAAA
void Test9()
{
    const char* matrix = "AAAAAAAAAAAA";
    const char* str = "AAAAAAAAAAAAA";

    Test("Test9", (const char*) matrix, 3, 4, str, false);
}

//A

//A
void Test10()
{
    const char* matrix = "A";
    const char* str = "A";

    Test("Test10", (const char*) matrix, 1, 1, str, true);
}

//A

//B
void Test11()
{
    const char* matrix = "A";
    const char* str = "B";

    Test("Test11", (const char*) matrix, 1, 1, str, false);
}

void Test12()
{
    Test("Test12", nullptr, 0, 0, nullptr, false);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();
    Test10();
    Test11();
    Test12();

    return 0;
}