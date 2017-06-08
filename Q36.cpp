/*BST与双向链表*/


#include<iostream>
#include "utils/BinaryTree.h"

using namespace std;

void ConvertNode(BinaryTreeNode* root, BinaryTreeNode** lastNodeinList);

BinaryTreeNode* ConvertTreetoList(BinaryTreeNode* root){

    if(root == nullptr)
        return nullptr;
    
    // 定义一个节点指针，指向转换好的链表的最后一个位置
    BinaryTreeNode* lastNodeinList = nullptr;

    ConvertNode(root, &lastNodeinList);

    // 上述转换完全之后，lastNodeinList 指向链表的最后一个位置，所以我们要返回 头结点
    BinaryTreeNode* headOfList = lastNodeinList;

    while(headOfList != nullptr && headOfList->m_pLeft != nullptr)
        headOfList = headOfList->m_pLeft;
    
    return headOfList;
}
// 注意指针
void ConvertNode(BinaryTreeNode* root, BinaryTreeNode** lastNodeinList){

    if(root == nullptr)
        return ;
    
    BinaryTreeNode* current = root;
    
    if(current->m_pLeft)
        ConvertNode(current->m_pLeft, lastNodeinList);
    
    current->m_pLeft = *lastNodeinList;

    if(*lastNodeinList != nullptr)
        
        // 注意加 括号！
        (*lastNodeinList)->m_pRight = current;
    
    *lastNodeinList = current;

    if(current->m_pRight)
        ConvertNode(current->m_pRight, lastNodeinList);
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

    BinaryTreeNode* result = ConvertTreetoList(pNode10);

    // 以链表的形式打印二叉搜索树
    while(result != nullptr){

        cout << result->m_nValue << ' ';
        result = result->m_pRight;
    }
    cout << endl;

    return 0;
}