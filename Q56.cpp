#include <iostream>
#include <vector>

using namespace std;

bool is_true_bit(int num, int index){

    return (num >> index) & 0x01;
}

void FindNumber(vector<int>& nums){

    if(nums.empty())
        return ;
    
    int xor_num = 0;
    // 找出两个只出现一次的数的 异或 结果， c = a ^ b
    for(int i = 0; i < nums.size(); ++i){

        xor_num = xor_num ^ nums[i];
    }

    int index = 0;
    while(index < 32){
        // 找出二进制表示中为1的位置index
        if(is_true_bit(xor_num, index))
        {
            break;
        }
        ++index;
    }

    int a = 0, b = 0;
    // 遍历数组中每个数，根据每个数第x位是0或1，分为两个子数组，分别进行异或，得出的那个数就是唯一只出现一次的数！
    for(int i = 0; i < nums.size(); ++i){

        if(is_true_bit(nums[i], index)){

            a = a ^ nums[i];
        }
        else
            b = b ^ nums[i];
    }

    cout << a << endl;
    cout << b << endl;
}

int main(){

    vector<int> nums = {2,4,3,3,6,2,5,5};
    
    FindNumber(nums);

    return 0;
}