/*数组奇数在前，偶数在后*/

#include<iostream>
#include<vector>

using namespace std;

void reverseArray(vector<int>& nums, int len){

    if(nums.empty())
        return ;
    
    int left = 0;
    int right = nums.size()-1;

    while(left < right){

        while(left<right && (nums[left] % 2) != 0)
            ++left;
        
        while(left<right && (nums[right] % 2) == 0)
            --right;
        
        if(left < right)
            swap(nums[left], nums[right]);
    }

}

int main(){

    vector<int> nums = {1,2,3,4,5};

    reverseArray(nums, 5);

    for(int i = 0; i < nums.size(); ++i){

        cout << nums[i] << endl;
    }
    return 0;
}