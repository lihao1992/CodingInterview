

#include<iostream>
#include "utils/BinaryTree.h"

BinaryTreeNode* KthCore(BinaryTreeNode* root, int& k);

    BinaryTreeNode* KthNode(BinaryTreeNode* pRoot, int k)
    {	
        if(pRoot == nullptr || k == 0)
            return nullptr;
       	
        return KthCore(pRoot, k);
        
    }
    
    // 函数参数中，传入的是整型引用 // 
    BinaryTreeNode* KthCore(BinaryTreeNode* root, int& k){
        
       	BinaryTreeNode* target = nullptr;
        
        if(root->m_pLeft != nullptr)
            target = KthCore(root->m_pLeft, k);
       	
        if(target == nullptr){
            
            if(k == 1)
                target = root;
            
            --k;
        }
        
        if(target == nullptr && root->m_pRight != nullptr)
            target = KthCore(root->m_pRight, k);
        
        return target;
    }

    int main(){


    }