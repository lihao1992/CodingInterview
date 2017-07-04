// 交换链表相邻节点
// 原始链表：1->2->3->4,
// 结果 ： 2->1->4->3 

class Solution{

    public:

        ListNode* swapPairs(ListNode* head){

            if(head == nullptr)
                return nullptr;
            
            ListNode* dummy = new ListNode(0);
            dummy->next = head;

            ListNode* pre = dummy;
            ListNode* cur = head;

            while(cur != nullptr && cur->next != nullptr){

                pre->next = cur->next;
                cur->next = cur->next->next;

                pre->next->next = cur;

                pre = cur;
                cur = cur->next;
            }
            return dummy->next;
        }
}