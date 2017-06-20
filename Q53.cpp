/*某个数在排序数组中出现的次数*/

#include<iostream>
#include<vector>

using namespace std;


int getFirstK(vector<int>& nums, int k, int len, int start, int end);

int getLastK(vector<int>& nums, int k, int len, int start, int end);


int countOfNumber(vector<int>& nums, int k){

    int len = nums.size();
    int count = 0;

    if(!nums.empty()){

        int first = getFirstK(nums, k, len, 0, len-1);

        int last = getLastK(nums, k, len, 0, len-1);

        if(first>-1 && last>-1)

            count = last-first+1;
    }

    return count;
    
}

int getFirstK(vector<int>& nums, int k, int len, int start, int end){

    if(start>end)
        return -1;
    
    // int mid = start + (end-start) >> 1; 报错：段错误（核心已转储）
    int mid = start + (end-start) / 2;
    int mid_data = nums[mid];

    if(mid_data == k){

        if(mid > 0 && nums[mid-1] != k || mid == 0)

            return mid;
        
        else
            end = mid-1;
    }
    else if(mid_data > k)

        end = mid-1;
    
    else
        start = mid+1;
    
    return getFirstK(nums, k, len, start, end);
}

int getLastK(vector<int>& nums, int k, int len, int start, int end){

    if(start>end)
        return -1;
    
    int mid = start + (end-start) / 2;
    int mid_data = nums[mid];

    if(mid_data == k){

        if(mid < len-1 && nums[mid+1] != k || mid == len-1)
            
            return mid;
        
        else
            start = mid+1;
    }
    else if(mid_data > k)
        
        end = mid-1;
    
    else 
        start = mid+1;
    
    return getLastK(nums, k, len, start, end);
}


int main(){

    vector<int> nums = {1, 2, 3, 3, 3, 3, 4, 5};

    cout << countOfNumber(nums, 3) << endl;

    return 0;
}