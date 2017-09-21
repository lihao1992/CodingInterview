/**/
#include <iostream>
#include <vector>

using namespace std;

int InversePairsCore(vector<int>&nums, vector<int>& copy, int start, int end);

int InversePairs(vector<int>& nums){

    if(nums.empty())
        return -1;
    
    int count = 0;
    vector<int> copy (nums);

    count = InversePairsCore(nums, copy, 0, nums.size()-1);

   
    return count;
}

int InversePairsCore(vector<int>&nums, vector<int>&copy, int start, int end){

    if(start == end){

        copy[start] = nums[start];
        return 0;
    }

    int mid = (end-start) >> 1;

    int left = InversePairsCore(nums, copy, start, start+mid);
    int right = InversePairsCore(nums, copy, start+mid+1, end);

    int i = start+mid;
    int j = end;

    int copyIndex = end;
    int count = 0;
   
    while(i>=start && j>=start+mid+1){

        if(nums[i] > nums[j]){

            copy[copyIndex--] = nums[i--];
            count += j-start-mid;
        }
        else
            copy[copyIndex--] = nums[j--];
    }
    for(; i>=start; --i)
        copy[copyIndex--] = nums[i];
    
    for(; j>=start+mid+1; --j)
        copy[copyIndex--] = nums[j];
    
    return left+right+count;
}

int main(){

    vector<int>nums = {5,4,6,2,3};

    int res = InversePairs(nums);

    cout << "inversePairs is :" << res << endl;

    return 0;
}
