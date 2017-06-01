/*最大价值*/


#include<iostream>
#include<vector>

using namespace std;

int MaxValue(const vector<vector<int>>& values, int rows, int cols){

    if(values.empty() || rows<=0 || cols>=0)
        return 0;
    
    vector<vector<int>> maxValue (rows, vector<int>(cols,0));

    for(int i = 0; i<rows; ++i){

        for(int j = 0; j<cols; ++j){

            int pre_max1 = 0;
            int pre_max2 = 0;
            
            if(i>0)
                pre_max1 = maxValue[i-1][j];
            
            if(j>0)
                pre_max2 = maxValue[i][j-1];
            
            maxValue[i][j] = max(pre_max1, pre_max2) + values[i][j];
        }
    }
    cout << maxValue[1][2];
    int result = maxValue[rows-1][cols-1];

    return result;
}

int solution2(vector<int>& values, int rows, int cols){

    if(values.size() == 0 || rows<=0 ||cols<=0){
        return 0;
    }

    vector<int>maxValue (cols, 0);

    for(int i = 0; i<rows; ++i){
        for(int j = 0; i<cols; ++j){

            int left = 0;
            int up = 0;

            if(i>0)
                up = maxValue[j];
            if(j>0)
                left = maxValue[j-1];
            
            maxValue[j] = max(up, left) + values[i*cols+j];
        }
    }

    int maxvalue = maxValue[cols-1];

    return maxvalue;
}

int main(){

    vector<int> values = {1,10,3,8,12,2,9,6,5,7,4,11,3,7,16,5};

   // cout << MaxValue(values, 4, 4) << endl;

   // cout << values[1][2]<< endl;

    cout << solution2(values, 4, 4) << endl;

    return 0;
}