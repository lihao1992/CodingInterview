/*层序遍历二叉树*/

#include<iostream>
#include<deque>
#include "utils/BinaryTree.h"

using namespace std;

void PrintTreeFromUpToDown(BinaryTreeNode* root){

    if(root == nullptr)
        return ;
    // 定义一个队列（STL deque）
    deque<BinaryTreeNode*> dequeTree;

    // store root
    dequeTree.push_back(root);

    while(dequeTree.size()){

        BinaryTreeNode* node = dequeTree.front();
        dequeTree.pop_front();
        cout << node->m_nValue << endl;

        if(node->m_pLeft)
            dequeTree.push_back(node->m_pLeft);
        
        if(node->m_pRight)
            dequeTree.push_back(node->m_pRight);
    }

}

int main(){

    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode61 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode62 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode51 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode71 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode72 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNode8, pNode61, pNode62);
    ConnectTreeNodes(pNode61, pNode51, pNode71);
    ConnectTreeNodes(pNode62, pNode72, nullptr);

    PrintTreeFromUpToDown(pNode8);

    return 0;
}
