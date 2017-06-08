/*二叉树的下一个节点*/
// 找出中序遍历的下一个节点，想一下，一共有几种情况
// 一共有三种情况：
// 1.当前节点是父节点的左子节点，那么它的下一个节点就是父节点；
// 2.当前节点有右子树，那么它的下一个节点就是右子树的最左子节点；
// 3.当前节点是父节点的右子节点，并且没有右子树，那么需要沿着指向父节点的指针向上遍历，直到遇到一个节点是它父节点的左子节点的时候，那么该节点的父节点便是我们要找的下一个节点

// 二叉树的数据结构中要有一个指向父节点的指针

#include<iostream>

using namespace std;

struct BinaryTreeNode {
    
    int m_nValue;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode* parent;

};

BinaryTreeNode* nextNode(BinaryTreeNode* pNode){

    if(pNode == nullptr)
        return nullptr;
    
    // 存最终结果
    BinaryTreeNode* next = nullptr;

    // 如果是情况2 
    if(pNode->right != nullptr){

        BinaryTreeNode* pRight = pNode->right;
        while(pRight->left != nullptr){

            pRight = pRight->left;
        }
        next = pRight;
    }

    // 情况1,3
    else if(pNode->parent != nullptr){

        BinaryTreeNode* pCurrent = pNode;
        BinaryTreeNode* pParent = pNode->parent;

        while(pParent != nullptr && pCurrent == pParent->right){

            pCurrent = pParent;
            pParent = pParent->parent;
        }

        next = pParent;
    }

    return next;
}

BinaryTreeNode* CreateBinaryTreeNode(int value){

    BinaryTreeNode* node = new BinaryTreeNode();
    node->m_nValue = value;
    node->left = nullptr;
    node->right = nullptr;
    node->parent = nullptr;

    return node;
}

void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pleft, BinaryTreeNode* pright){

    if(pParent != nullptr){

        pParent->left = pleft;
        pParent->right = pright;

        if(pleft != nullptr)
            pleft->parent = pParent;
        
        if(pright != nullptr)
            pright->parent = pParent;

    }
}

void PrintTreeNode(BinaryTreeNode* pNode)
{
    if(pNode != nullptr)
    {
        cout << "value of this node is:" << pNode->m_nValue << endl;

        if(pNode->left != nullptr)
            cout << "value of its left child is:" << pNode->left->m_nValue << endl;
        else
            cout << "left child is null." << endl;

        if(pNode->right != nullptr)
            printf("value of its right child is: %d.\n", pNode->right->m_nValue);
        else
            printf("right child is null.\n");
    }
    else
    {
        printf("this node is null.\n");
    }

    printf("\n");
}

void PrintTree(BinaryTreeNode* root){

    PrintTreeNode(root);

    if(root != nullptr){

        if(root->left != nullptr)
            PrintTree(root->left);
        
        if(root->right != nullptr)
            PrintTree(root->right);
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

    BinaryTreeNode* pNext = nextNode(pNode8);
    cout << pNext->m_nValue << endl;

    BinaryTreeNode* pNext1 = nextNode(pNode7);
    cout << pNext1->m_nValue << endl;

    return 0;
}