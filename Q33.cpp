/*BST的后序遍历*/
// 判断是否是前序遍历，那么就是数组的第一个数就是BST的根节点

#include<iostream>
#include<vector>
#include "utils/BinaryTree.h"

using namespace std;

// 为什么不用vector， 是因为递归判断数组中右子树的时候，是在数组中间开始的，那么传递给函数的起始位置应该从头位置移动到中间某个位置（nums+i），如果nums定义为vector，我还是不知道怎么传递
bool isPostOrderOfBST(int nums[], int len){

    if(nums==nullptr || len <= 0)
        return false;
    
    // 根节点就是数组的最后一个数
    int root = nums[len-1];

    // check 左子树节点的个数，左子树节点应该都小于根节点，所以如果碰见比根节点大的，就是说明左子树结束了
    int i = 0;
    for(; i<len-1; ++i){

        if(nums[i] > root)
            break;
    }

    // 从左子树结束的位置遍历，查看 后面的节点是否都大于根节点（BST的右子数定义），如果有不符合的节点出现，那么数组不是二叉树的后序遍历 ！
    int j = i;
    for(; j<len-1; ++j){

        if(nums[j] < root)
            return false;
    }

    // 递归check 左子树是否是 BST
    bool left = true;
    if(i>0)
        left = isPostOrderOfBST(nums, i);
    
    // 递归check 右子树是否是 BST
    bool right = true;
    if(i<len-1)
        right = isPostOrderOfBST(nums+i, len-1-i);
    
    return (left && right);
}

int main(){

    int nums[] = {5,7,6,9,11,10,8};

    if(isPostOrderOfBST(nums, 7))
        cout << "Yes" << endl;
    
    else
        cout << "Not" << endl;

    return 0;
}