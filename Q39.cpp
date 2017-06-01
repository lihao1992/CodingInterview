/*数组中出现次数超过一半的数字*/
// 从数组头开始遍历，维护一个计数器，如果当前数字没有出现过，那么计数器设为1，如果下个数相同，计数器加1，如果不同，计数器减1；
// 数组中超过一半的那个数，比其余的数出现次数的总和还要多，所以我们要找的结果就是 那个最后将计数器设为1的数。
// 时间复杂度O(N)
#include<iostream>
#include<vector>

using namespace std;

bool checkInvalidArray(vector<int>& nums, int len);
bool checkMoreThanHalf(vector<int>& nums, int len, int result);

int findNumber(vector<int>&nums){

    int len = nums.size();
    // 检查输入的数组是否有效
    if(checkInvalidArray(nums, len))
        return 0;
    
    int result = nums[0];
    int times = 1;
    for(int i = 1; i<len; ++i){

        if(times == 0){
            
            result = nums[i];
            times = 1;
        }
        else if(nums[i] == result)
            ++times;
        
        else
            --times;
    }

    // 检查我们得到的结果数字，出现次数有没有超过一半
    if(!checkMoreThanHalf(nums, len, result))
        return 0;
    
    return result;
}

bool checkInvalidArray(vector<int>& nums, int len){

    if(nums.empty() || len <= 0)
        return true;
    
    else
        return false;
}

bool checkMoreThanHalf(vector<int>& nums, int len, int result){

    int times = 0;
    // 计算目标值出现的次数
    for(int i = 0; i<len; ++i){
        
        if(nums[i] == result)
            ++times;
    }
    // 如果出现次数没有超过一半，返回false
    if(times*2 <= len){
        return false;
    }
    return true;
}

int main(){

    vector<int> nums = {1,2,3,2,2,2,5,4,2};
    
    cout << findNumber(nums) << endl;

    return 0;
}