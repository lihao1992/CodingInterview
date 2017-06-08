/* 求二叉树的深度 */

#include<iostream>
#include "utils/BinaryTree.h"

using namespace std;

// 递归实现树的深度
int depthOfTree(BinaryTreeNode* root){
    //如果根节点不为空，则继续遍历根节点的左子树，右子树
    if(root == nullptr)
        return 0;
    
    int d_left = depthOfTree(root->m_pLeft);
    int d_right = depthOfTree(root->m_pRight);

    return (d_left > d_right) ? (d_left+1) : (d_right+1);
}

int main(){

    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode14 = CreateBinaryTreeNode(14);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
    BinaryTreeNode* pNode16 = CreateBinaryTreeNode(16);

    ConnectTreeNodes(pNode10, pNode6, pNode14);
    ConnectTreeNodes(pNode6, pNode4, pNode8);
    ConnectTreeNodes(pNode14, pNode12, pNode16);

    cout << depthOfTree(pNode10) << endl;

    return 0;
}