/*重建二叉树*/

#include<iostream>
#include<vector>

using namespace std;

struct BinaryTree{

    int value;
    BinaryTree* left;
    BinaryTree* right;
};

BinaryTree* ConstructCore(int *startPreOrder, int* endPreOrder, int* startInorder, int* endInorder);

BinaryTree* Construct(vector<int>& preorder, vector<int>& inorder, int len){

    if(preorder.empty() || inorder.empty() || len<=0){
        return ;
    }

    return ConstructCore(preorder, preorder+len-1,
                            inorder, inorder+len-1);
}

BinaryTree* ConstructCore(int *startPreOrder, int* endPreOrder, int* startInorder, int* endInorder){

    int rootvalue = startPreOrder[0];

    BinaryTree* root = new BinaryTree();
    root->value = rootvalue;
    root->left = root->right = nullptr;

    if(startPreOrder == endPreOrder){

        if(startInOrder == endInOrder && *startPreOrder == *startInOrder)

            return root;
        
        else{

            throw std::exception("invalid input");
        }
    }

    int* rootInorder = startInOrder;
    
    while(rootInorder <= endInOrder && *rootInorder != rootvalue)
        ++rootInorder;
    
    if(rootInorder == endInOrder && *rootInorder != rootvalue)
        throw std::exception("invalid input");
    
    int leftLen = rootInorder - startInOrder;

    int* leftPreOrderEnd = startPreOrder + leftLen;

    if(leftLen > 0){

        root->left = ConstructCore(startPreOrder+1, leftPreOrderEnd, startInOrder, rootInorder-1);
    }

    if(leftLen < endPreOrder - startPreOrder){

        root->right = ConstructCore(leftPreOrderEnd+1, endPreOrder, rootInorder+1, endInOrder);
    }

    return root;
}