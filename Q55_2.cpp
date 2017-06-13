/**/

#include<iostream>
#include "utils/BinaryTree.h"

bool isBalance(BinaryTreeNode* root, int* depth);

bool isBalance(BinaryTreeNode* root){

    int depth = 0;
    return isBalance(root, &depth);
}

bool isBalance(BinaryTreeNode* root, int* depth){

    if(root == nullptr){

        *depth = 0;
        return true;
    }

    int left,right;
    if(isBalance(root->m_pLeft, &left) && isBalance(root->m_pRight, &right)){

        int diff = left-right;

        if(diff >= -1 && diff <= 1){

            *depth = 1+(left>right? left : right);
            return true;
        }
    }

    return false;
}


int main(){

    
}