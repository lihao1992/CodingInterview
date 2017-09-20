/* 数组中唯一出现一次的数（其余数字都出现三次！） */

#include <iostream>
#include <vector>

using namespace std;

void findNumber(vector<int>&nums){

    if(nums.empty())
        cerr << "invalid input.";
    
    int bitSum[32] = {0};
    for(int i = 0; i < nums.size(); ++i){

        int bitMask = 1;
        for(int j = 31; j >= 0; --j){

            int bit = nums[i] & bitMask;
            if(bit != 0)
                bitSum[j] += 1;

            bitMask = bitMask << 1;
        }
    }

    int res = 0;
    for(int i = 0; i < 32; ++i){

        res = res << 1;
        res += bitSum[i] % 3;
    }

    cout << res << endl;
}

int main(){

    vector<int> nums = {2,4,2,4,5,1,2,4,1,1};
    vector<int> nums_test = {};

    findNumber(nums);
    findNumber(nums_test);
    cout << 1 << endl;
    return 0; 
}