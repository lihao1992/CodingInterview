/*二叉树中和为某一值的路径*/

// 既然是求路径，那么路径自然是从根节点出发，所以本题应该是前序遍历的思想
// 为了求路径，当我们遍历节点的时候，要将遍历过的节点保存起来，同时计算节点值的和是否等于target
// 当我们求得一条路径的值刚好为target的时候，我们将保存的路径打印！
// 当我们遍历到叶节点，路径都不等于target/路径上的值的和大于target的时候，那么我们应该把当前节点从路径中删除，
// 当我们要重新寻找下一条路径的时候，我们要在路径上删除当前节点，并减去当前节点的值，以确保返回父节点时，路径保存的是从根节点到父节点！
// 所以这里就要用到 栈 的思想！

#include<iostream>
#include<vector>
#include "utils/BinaryTree.h"

using namespace std;

void PrintPath(BinaryTreeNode* root, int target, vector<int>& path, int currentSum);

void PrintPath(BinaryTreeNode* root, int target){

    if(root == nullptr)
        return ;
    
    vector<int> path;
    int currentSum = 0;

    PrintPath(root, target, path, currentSum);
}

void PrintPath(BinaryTreeNode* root, int target, vector<int>& path, int currentSum){

    // 求当前路径上的和
    currentSum += root->m_nValue;
    // 将当前节点加入到路径中
    path.push_back(root->m_nValue);

    bool isLeaf = (root->m_pLeft == nullptr && root->m_pRight == nullptr);

    if(currentSum == target && isLeaf){

        cout << "path is found:" ;

        vector<int>::iterator it = path.begin();
        for( ;it != path.end(); ++it)
            cout << *it << ' ';

        cout << endl;
    }

    // 如果不是叶节点
    if(root->m_pLeft)
        PrintPath(root->m_pLeft, target, path, currentSum);
    
    if(root->m_pRight)
        PrintPath(root->m_pRight, target, path, currentSum);
    
    // 返回父节点之前，要将当前节点在路径上删除
    path.pop_back();
}
// 可以看出整体架构是去 前序遍历 的思想！先根节点，左子树，再右子树

int main(){

    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode9 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);

    ConnectTreeNodes(pNode8, pNode6, pNode10);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);

    PrintPath(pNode8, 21);

    return 0;
}