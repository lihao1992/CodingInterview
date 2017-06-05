/*链表中环的入口节点*/
// 分析该题首先，要确定链表中有环，
// 1.通过快慢指针，得知链表是否有环，记录相遇位置；
// 2.已知存在环，并记录了快满指针相遇位置，那么此相遇位置一定在环中！计算欢中节点的个数m
// 3.同样设置两指针，从头结点开始，一个先走m步，然后两个指针同时走，这样当两个指针再次相遇时，
// 后走的指针刚好指向环的入口，先走的指针是走完环一圈后，又回到了环的入口！

#include<iostream>
#include "utils/list.h"

using namespace std;

ListNode* MeetingNode(ListNode* pHead){

    if(pHead == nullptr)
        return nullptr;
    
    ListNode* slow = pHead;
    ListNode* fast = pHead;

    if(fast == nullptr || fast->m_pNext == nullptr)
        return nullptr;
    
    while(fast != nullptr && slow != nullptr){

        slow = slow->m_pNext;
        fast = fast->m_pNext;
        if(fast != nullptr)
            fast = fast->m_pNext;
        
        if(fast == slow)
            return fast;
    }
    // 链表不存在环
    return nullptr;
}

ListNode* enterOFloop(ListNode* pHead){

    ListNode* meetingNode = MeetingNode(pHead);
    if(meetingNode == nullptr)
        return nullptr;
    
    // 计算环中节点数
    int count = 1;
    ListNode* node1 = meetingNode;
    while(node1->m_pNext != meetingNode){

        ++count;
        node1 = node1->m_pNext;
    }

    // 确定环的入口
    node1 = pHead;
    ListNode* node2 = pHead;
    // node1先走count步
    for(int i = 0; i<count; ++i){

        node1 = node1->m_pNext;
    }
    while(node1 != node2){

        node1 = node1->m_pNext;
        node2 = node2->m_pNext;
    }
    return node1;

}

int main(){

    ListNode* node1 = CreateListNode(1);
    ListNode* node2 = CreateListNode(2);
    ListNode* node3 = CreateListNode(3);
    ListNode* node4 = CreateListNode(4);
    ListNode* node5 = CreateListNode(5);
    ListNode* node6 = CreateListNode(6);

    ConnectListNodes(node1, node2);
    ConnectListNodes(node2, node3);
    ConnectListNodes(node3, node4);
    ConnectListNodes(node4, node5);
    ConnectListNodes(node5, node6);
    ConnectListNodes(node6, node3);

   // PrintList(node1);
    ListNode* result = enterOFloop(node1);
    PrintListNode(result);

    return 0;
}