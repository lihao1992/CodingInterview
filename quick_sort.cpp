
#include<iostream>
#include<vector>

using namespace std;

void quick_sort(vector<int>& num, int left, int right){
    
    if(num.empty() || left > right) return ;

    int i = left;
    int index = num[left];
    // 注意是 j<=right ,有等号
    for(int j = left+1; j <= right; ++j){

        if(num[j] < index){

            ++i;
            if(i!=j)
                swap(num[i], num[j]);
        }
    }
    swap(num[i], num[left]);
    quick_sort(num, left, i-1);
    quick_sort(num, i+1, right);
}

int main(){

    vector<int> nums = {6,2,5,4,7,0,8};
    int left = 0;
    int right = nums.size()-1;
    quick_sort(nums, left, right);
    
    for(int i = 0; i < nums.size(); ++i)
        cout << nums[i] << endl;

    return 0;
}