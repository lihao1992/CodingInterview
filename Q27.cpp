/*二叉树的镜像*/
// 求树的镜像，就是在遍历树的同时，交换非叶节点的左右子节点

#include<iostream>
#include "utils/BinaryTree.h"

using namespace std;

void MirrorOfBinaryTree(BinaryTreeNode* pRoot){

    if(pRoot == nullptr)
        return ;
    
    // 只有一个节点
    if(pRoot->m_pLeft == nullptr && pRoot->m_pRight == nullptr)
        return ;

    // 交换非叶节点的左右子节点
    BinaryTreeNode* tmp = pRoot->m_pLeft;
    pRoot->m_pLeft = pRoot->m_pRight;
    pRoot->m_pRight = tmp;

    // 递归遍历
    if(pRoot->m_pLeft)
        MirrorOfBinaryTree(pRoot->m_pLeft);

    if(pRoot->m_pRight)
        MirrorOfBinaryTree(pRoot->m_pRight);
}

int main(){

    BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNodeA5 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNodeA6 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNodeA7 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNodeA1, pNodeA2, pNodeA3);
    ConnectTreeNodes(pNodeA2, pNodeA4, pNodeA5);
    ConnectTreeNodes(pNodeA5, pNodeA6, pNodeA7);

    PrintTree(pNodeA1);

    MirrorOfBinaryTree(pNodeA1);

    PrintTree(pNodeA1);

    return 0;
}