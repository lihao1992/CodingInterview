/*对称的二叉树*/
// 重新设定一种遍历方式，比如我们用前序遍历二叉树，先遍历根节点，左子节点，右子节点
// 那么前序对称遍历二叉树，就先遍历根节点，右子节点，左子节点
// 判断这两次遍历得到的序列是否相等？ 

#include<iostream>
#include "utils/BinaryTree.h"

using namespace std;

bool isSymmetrical(BinaryTreeNode* root1, BinaryTreeNode* root2);

bool isSymmetrical(BinaryTreeNode* root){

    return isSymmetrical(root, root);
}

bool isSymmetrical(BinaryTreeNode* root1, BinaryTreeNode* root2){

    // 如果遍历到叶节点的话，那么再遍历下去，是nullptr，我们也保存到遍历序列中，防止因结构而不对称的二叉树（两次遍历序列一致，但二叉树的结构不一致）的判断错误
    if(root1 == nullptr && root2 == nullptr)
        return true;
    
    if(root1 == nullptr || root2 == nullptr)
        return false;
    
    if(root1->m_nValue != root2->m_nValue)
        return false;
    
    return (isSymmetrical(root1->m_pLeft, root2->m_pRight) &&
            isSymmetrical(root1->m_pRight, root2->m_pLeft));

}

int main(){

    //            8
    //        6      6
    //       5 7    7

    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode61 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode62 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode51 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode71 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode72 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNode8, pNode61, pNode62);
    ConnectTreeNodes(pNode61, pNode51, pNode71);
    ConnectTreeNodes(pNode62, pNode72, nullptr);

    if(isSymmetrical(pNode8))
        cout << "Yes" << endl;
    else
        cout << "Not" << endl;


//               5
//              / \
//             3   3
//            /     \
//           4       4
//          /         \
//         2           2
//        /             \
//       1               1

    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode31 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode32 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode41 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode42 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode21 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode22 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode11 = CreateBinaryTreeNode(1);
    BinaryTreeNode* pNode12 = CreateBinaryTreeNode(1);

    ConnectTreeNodes(pNode5, pNode31, pNode32);
    ConnectTreeNodes(pNode31, pNode41, nullptr);
    ConnectTreeNodes(pNode32, nullptr, pNode42);
    ConnectTreeNodes(pNode41, pNode21, nullptr);
    ConnectTreeNodes(pNode42, nullptr, pNode22);
    ConnectTreeNodes(pNode21, pNode11, nullptr);
    ConnectTreeNodes(pNode22, nullptr, pNode12);

    if(isSymmetrical(pNode5))
        cout << "Yes" << endl;
    else
        cout << "Not" << endl;


    return 0;
}