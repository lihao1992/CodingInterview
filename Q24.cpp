/*反转链表*/


#include<iostream>
#include "utils/list.h"

using namespace std;

ListNode* reverseList(ListNode* pHead){

    if(pHead == nullptr)
        return nullptr; 
    
    ListNode* result = nullptr;

    ListNode* node = pHead;
    ListNode* pre = nullptr;

    // 定义3个指针，当前节点；当前节点的前一个节点；当前节点的下一个节点
    while(node != nullptr){
        // 防止链表断裂，必须保存当前节点的下一节点
        ListNode* next = node->m_pNext;

        // 链表的尾节点就是反转过后的头节点
        if(next == nullptr)
            result = node;
        
        node->m_pNext = pre;

        pre = node;
        node = next;
    }
    return result;
}

int main(){


    ListNode* node1 = CreateListNode(1);
    ListNode* node2 = CreateListNode(2);
    ListNode* node3 = CreateListNode(3);
    ListNode* node4 = CreateListNode(4);
    ListNode* node5 = CreateListNode(5);

    ConnectListNodes(node1, node2);
    ConnectListNodes(node2, node3);
    ConnectListNodes(node3, node4);
    ConnectListNodes(node4, node5);

    PrintList(node1);

    ListNode* result = reverseList(node1);
    PrintList(result);

    // 链表中只有一个节点
    ListNode* node7 = CreateListNode(7);
    PrintList(node7);
    ListNode* result1 = reverseList(node7);
    PrintList(result1);

    return 0;
}
