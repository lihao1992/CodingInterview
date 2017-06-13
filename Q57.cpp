/*和为s的数字*/
// 双指针，前后各一个，时间复杂度O(n)

#include<iostream>
#include<vector>

using namespace std;

bool findNumberWithsum(vector<int>& nums, int sum, vector<int>& result){

    bool found = false;

    if(nums.empty())
        return found;
    
    int first = 0;
    int second = nums.size()-1;

    while(first < second){

        // 防止大数溢出
        long long curSum = nums[first] + nums[second];
        if(curSum == sum){

            found = true;
            result.push_back(nums[first]);
            result.push_back(nums[second]);
            break;
        }
        else if(curSum > sum)
            --second;
        
        else
            ++first;
    }

    return found;
}

int main(){

    vector<int> nums ={1,2,4,7,11,15};

    vector<int> result ;

    if(findNumberWithsum(nums, 15, result)){
        for(vector<int>::iterator it=result.begin(); it != result.end(); ++it)
            cout << *it << endl;
    }
    else
        cout << "not" << endl;

    return 0;
}