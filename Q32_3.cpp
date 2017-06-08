/*之字形打印二叉树（zigzag）*/
// 两个栈

#include<iostream>
#include<stack>
#include "utils/BinaryTree.h"

using namespace std;

void PrintByZigzag(BinaryTreeNode* root){

    if(root == nullptr)
        return ;
    
    // 设置两个栈，当打印一个节点时，它的子节点保存在另外一个栈里
    stack<BinaryTreeNode*> level[2];
    int current = 0;
    int next = 1;

    level[current].push(root);

    while(!level[0].empty() || !level[1].empty()){

        BinaryTreeNode* node = level[current].top();
        cout << node->m_nValue << ' ';
        level[current].pop();

        if(current == 0){

            if(node->m_pLeft){
            
                level[next].push(node->m_pLeft);
            }
            if(node->m_pRight){
                level[next].push(node->m_pRight);
            }
        }
        else{

            if(node->m_pRight){
                level[next].push(node->m_pRight);
            }
            if(node->m_pLeft){
                level[next].push(node->m_pLeft);
            }
        }

        if(level[current].empty()){

            cout << endl;
            current = 1-current;
            next = 1-next;

        }
    }
}

int main(){

    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);

    ConnectTreeNodes(pNode8, pNode6, pNode10);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);

    PrintByZigzag(pNode8);

    return 0;
}