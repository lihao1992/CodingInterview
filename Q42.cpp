/*连续子数组的最大和*/

#include<iostream>
#include<vector>

using namespace std;

bool Invalid_input = false;

int findGreatestSum(vector<int>& nums){

    // 注意当数组输入无效时，返回值为0，这就可能与最大和为0的结果冲突，
    // 所以需要维护一个全局变量来标记是否是由无效输入导致的返回值为0。
    if(nums.empty()){

        Invalid_input = true;
        return 0;
    }

    int curSum = 0;
    // 维护的最终结果初始化的时候，不能为0，因为当输入所有数均为负数时，结果不为0，是负数
    //int finalSum = 0x80000000;
    int finalSum = nums[0];

    for(int i = 0; i < nums.size(); ++i){

        if(curSum <= 0){
            curSum = nums[i];
        }
        else{

            curSum += nums[i];
        }

        if(curSum > finalSum)
            finalSum = curSum;
    }
    return finalSum;
}

int main(){

    vector<int> nums = {1,-2,3,10,-4,7,2,-5};
    vector<int> nums2 = {5,1,2,3,4,8,6};
    vector<int> nums3 = {-4, -2, -3, -1, -5};
    vector<int> nums4 = {};

    cout << findGreatestSum(nums) << endl;
    cout << findGreatestSum(nums2) << endl;
    cout << findGreatestSum(nums3) << endl;
    cout << findGreatestSum(nums4) << endl;

    return 0;
}