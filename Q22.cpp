/*链表的倒数第k个节点*/
// 双指针，一次遍历

#include<iostream>
#include "utils/list.h"

using namespace std;

ListNode* findKthNumberFromTail(ListNode* pHead, int k){

    if(pHead == nullptr || k <= 0)
        return nullptr;
    
    ListNode* fast = pHead;
    ListNode* slow = pHead;

    for(int i = 0; i<k-1; ++i){

        if(fast->m_pNext != nullptr)
            fast = fast->m_pNext;
        
        // 链表的总结点数不超过k个
        else{
            return nullptr;
        }
    }

    // 当快指针走到链表尾部，慢指针正好与它相隔k个位置，所以找到倒数第k个位置
    while(fast->m_pNext != nullptr){

        fast = fast->m_pNext;
        slow = slow->m_pNext;
    }

    // (2) cout << "倒数kth个节点的值：" << slow->m_nValue << endl;
    //(1) return slow;
    return slow; // (3)
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

    PrintList(node1);

    // 直接返回的话，应该得到的是存放倒数第ｋ个节点的地址
    // (1) cout << findKthNumberFromTail(node1, 2) << endl;
    
    // (2) findKthNumberFromTail(node1,2);

    // (3)
    ListNode* result = findKthNumberFromTail(node1, 6);
    PrintListNode(result);


    return 0;
}