/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    // 复杂链表复制
    
    // 第一步，将原链表的每个节点N，创建N‘, 并且新创建的N’ 链接在原始节点的后面！！
    void copyFunc(RandomListNode* head){
        
        if(head == nullptr)
            return ;
        
        RandomListNode* pNode = head;
        if(pNode != nullptr){
            
            RandomListNode* copyNode = new RandomListNode();
            copyNode->label = pNode->label;
            copyNode->next = pNode->next;
            copyNode->random = nullptr;
            
            pNode->next = copyNode;
            
            pNode = copyNode->next;
        }
        
    }
    
    // 第二步，假如原始节点的random指针指向节点S，那么拷贝节点N‘的random指针同样指向S’，而s'是链接在s后面的！！
    void findRandomPointer(RandomListNode* head){
        
        if(head == nullptr)
            return ;
        
        RandomListNode* pNode = head;
        while(pNode != nullptr){
            // 通过第一步，拷贝节点已经复制在了每个原始节点的后面
            RandomListNode* copyNode = pNode->next;
            if(pNode->random != nullptr){
                
                copyNode->random = pNode->random->next;
            }
            pNode = copyNode->next;
        }
    }
    
    // 第三步，将整个链表拆分，将原始链表链接在一起， 同时将拷贝链表连接在一起！！
    RandomListNode* connectCopyList(RandomListNode* head){
        
        RandomListNode* pNode = head;
        RandomListNode* copyListHead = nullptr;
        RandomListNode* copyNode = nullptr;
        
        while(pNode != nullptr){
            
            copyListHead = pNode->next;
            copyNode = pNode->next;
            
            pNode->next = copyNode->next;
            
            pNode = copyNode->next;
        }
        
        //pNode = head;
        //copyListHead = copyNode = pNode->next;
        
        while(pNode != nullptr){
            
            copyNode->next = pNode->next;
            copyNode = copyNode->next;
            
            pNode->next = copyNode->next;
            pNode = pNode->next;
            
        }
        
        return copyListHead;
    }
    
    
    RandomListNode *copyRandomList(RandomListNode *head) {
        
        copyFunc(head);
        findRandomPointer(head);
        
        return connectCopyList(head);
    }
};