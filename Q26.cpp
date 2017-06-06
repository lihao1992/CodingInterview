/*树的子结构*/
// 1.在树A中查找与树B根节点值相同的节点R
// 2.判断树A中，以R为根节点的子树是否包含树B的结构
// 递归

#include<iostream>
#include "utils/BinaryTree.h"

using namespace std;

bool checkTree1HasTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2);

bool isSubTree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2){

    if(pRoot2 == nullptr || pRoot1 == nullptr)
        return false;
    
    bool result = false;

    if(pRoot1 != nullptr && pRoot2 != nullptr){

        if(pRoot1->m_nValue == pRoot2->m_nValue){

            result = checkTree1HasTree2(pRoot1, pRoot2);
        }

        if(!result){

            result = isSubTree(pRoot1->m_pLeft, pRoot2);
        }
        if(!result){

            result = isSubTree(pRoot1->m_pRight, pRoot2);
        }
    }
    return result;
}

bool checkTree1HasTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2){

    if(pRoot2 == nullptr)
        return true;
    
    if(pRoot1 == nullptr)
        return false;
    
    if(pRoot1->m_nValue != pRoot2->m_nValue)
        return false;
    
    return (checkTree1HasTree2(pRoot1->m_pLeft, pRoot2->m_pLeft) && 
            checkTree1HasTree2(pRoot1->m_pRight, pRoot2->m_pRight));
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

    BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pNodeB1, pNodeB2, pNodeB3);

    if(isSubTree(pNodeA1, pNodeB1))
        cout << "TreeB is subtree of TreeA ." << endl;
    
    else
        cout << " NOT " << endl;
    
    return 0;
}