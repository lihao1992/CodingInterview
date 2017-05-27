/*旋转数组的最小值*/

#include<iostream>
#include<vector>

using namespace std;

int findInOrder(vector<int>& nums, int left, int right);

int findMinNumber(vector<int>& nums){

    if(nums.empty())    
        cout << "invalid parameters";

    int left = 0;
    int right = nums.size()-1;
    int target = left;

    while(nums[left] >= nums[right]){

        // 如果前后两部分查找到相邻位置，那么说明后一部分已经到了整个数组的最小的数的位置（也就是未旋转时候，有序数组的第一个数）
        if(right - left == 1){
            target = right;
            break;
        }
         
        //target = (left+right) >> 1;
        target = left + (right-left)/2;

        if(nums[target] >= nums[left])
            left = target;
        
        if(nums[target] <= nums[right])
            right = target;
        
        // 如果左右指针和中间值均指向相同的值，那么二分查找不能完成搜索，所以只能利用顺序查找
        else if(nums[left] == nums[target] && nums[left] == nums[right])
            return findInOrder(nums, left, right);
    }
    return nums[target];
}

int findInOrder(vector<int>& nums, int left, int right){

    int result = nums[left];
    for(int i = left+1; i<=right; ++i){

        if(result > nums[i])
            result = nums[i];
    }

    return result;
}

int main(){

    vector<int> nums = {4,5,6,7,8,2,3};
    cout << findMinNumber(nums) << endl;

    return 0;
}