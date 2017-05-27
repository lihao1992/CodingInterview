/* 求二叉树的深度 */

struct BinaryTree{

    int data;
    BinaryTree* left;
    BinaryTree* right;
}

// 递归实现树的深度
int depthOfTree(BinaryTree* root){
    //如果根节点不为空，则继续遍历根节点的左子树，右子树
    if(root == nullptr)
        return 0;
    
    int d_left = depthOfTree(root->left);
    int d_right = depthOfTree(root->right);

    return (d_left > d_right) ? (d_left+1) : (d_right+1);
}