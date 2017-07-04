// 删除链表中倒数第n个节点


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head == nullptr)
            return nullptr;
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        // 链表中只有一个节点
        if(head->next == nullptr && 1 == n){
            
            head = nullptr;
        }
        
        // 链表中有多个节点，删除末尾节点
        else if(head->next != nullptr && 1==n){
            
            ListNode* pNode = head;
            ListNode* pre = nullptr;
            while(pNode->next != nullptr){
                pre = pNode;
                pNode = pNode->next;
                pre->next = pNode;
            }
            pre->next = nullptr;
            delete pNode;
            pNode = nullptr;
            
        }
        
        // 链表中有多个节点，删除中间某个节点    
            for(int i = 0; i < n-1; ++i){
            
                if(fast->next != nullptr)
            
                    fast = fast->next;
                else
                    return nullptr;
            }
            while(fast->next != nullptr){
                slow = slow->next;
                fast = fast->next;
            }
        
        if(slow->next != nullptr){
            
            ListNode* p_Next = slow->next;
            slow->val = p_Next->val;
            slow->next = p_Next->next;
            
            delete p_Next;
            p_Next = nullptr;
        }
        
        return head;
        
    }
};