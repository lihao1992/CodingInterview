/**/

#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int>& nums1, int n1, vector<int>& nums2, int n2){

    int len = n1+n2;
    while(n1>0 && n2>0){

        if(nums1[n1-1] > nums2[n2-1]){
            nums1[len-1] = nums1[n1-1];
            --n1;
        }
        else{
            nums1[len-1] = nums2[n2-1];
            --n2;
        }
        --len;
    }

    while(n2 > 0){
        nums1[len-1] = nums2[n2-1];
        --n2;
        --len;
    }
}

int main(){

    vector<int> nums1 = {1,3,5,7,9};
    vector<int> nums2 = {2,4,6,8,10};
    merge(nums1, nums1.size(), nums2, nums2.size());

    int len = nums1.size() + nums2.size();
    for(int i = 0; i<len; ++i)
        cout << nums1[i] <<",";
    
    return 0;
}