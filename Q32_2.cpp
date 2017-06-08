/*按行层序遍历二叉树*/
// 保证每层二叉树节点，打印到一行
// 设置两个变量，一个存当前行还没有打印的节点数，一个存下一层一共有几个节点

#include<iostream>
#include<deque>
#include "utils/BinaryTree.h"

using namespace std;

void PrintByRow(BinaryTreeNode* root){

    if(root == nullptr)
        return ;

    deque<BinaryTreeNode*> dequeList;

    dequeList.push_back(root);
    int tobePrint = 1;
    int nextRow = 0;

    while(dequeList.size()){

        BinaryTreeNode* node = dequeList.front();
        cout << node->m_nValue;
        
        if(node->m_pLeft){
            dequeList.push_back(node->m_pLeft);
            ++nextRow;
        }
        if(node->m_pRight){
            dequeList.push_back(node->m_pRight);
            ++nextRow;
        }
        // 每次当前行打印一个之后，tobePrint减 1
        dequeList.pop_front();
        --tobePrint;

        // 当当前行没有待打印的时候，输出换行符，同时将下一行的节点数传入到tobePrint中
        if(tobePrint == 0){
            
            cout << endl;

            tobePrint = nextRow;
            nextRow = 0;
        }
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

    PrintByRow(pNode8);

    return 0;
}