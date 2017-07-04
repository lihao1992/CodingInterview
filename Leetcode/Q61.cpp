// 旋转链表
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 ListNode* rotateList(ListNode* head, int k){

     if(head == nullptr)
        return nullptr;
    
    int len = 1;
    ListNode *newHead = head;
    ListNode* pNode = head;

    while(pNode->next != nullptr){
        
        ++len;
        pNode = pNode->next;
    }

    pNode->next = head; // 将链表尾部接到头部，形成环！！

    if(k %= len){

        for(int i = 0; i < len-k; ++i)
            pNode = pNode->next;
    }
    
    newHead = pNode->next;
    pNode->next = nullptr;

    return newHead;
 }


// 超时了！！！！
 ListNode* rotateList(ListNode* head, int k){

    if(head == nullptr || k<0)
        return nullptr;
    
    ListNode* fast = head;
    ListNode* slow = head;

    if(head->next != nullptr && k == 1){

        ListNode* pNode = head;
        ListNode* pre = nullptr;
        while(pNode->next != nullptr){
            pre = pNode;
            pNode = pNode->next;
            pre->next = pNode;
        }
        pre->next = nullptr;
        pNode->next = head;
        ListNode* dummy = new ListNode(0);
        dummy->next = pNode;

        return dummy->next;
    }

    else if(head->next == nullptr && k == 1)
        return head;
    
else{
    
    ListNode* pre = nullptr;
    
    for(int i = 0; i<k-1; ++i){
        
        if(fast->next != nullptr)
            fast = fast->next;
        else 
            return nullptr;
    }
    while(fast->next != nullptr){

        pre = slow;
        slow = slow->next;
        pre->next = slow;
        
        fast = fast->next;
    }
    //pre->next = nullptr;
    fast->next = head;
    ListNode* dummy = new ListNode(0);
    dummy->next = slow;
    
   //pre->next = nullptr;

    return dummy->next;
    }
    
   
}