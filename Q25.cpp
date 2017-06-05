/*合并两个有序链表*/
// 分析出哪些情况，会输入空指针，导致程序崩溃 是关键！

#include<iostream>
#include "utils/list.h"

using namespace std;

ListNode* mergeList(ListNode* pHead1, ListNode* pHead2){

    if(pHead1 == nullptr && pHead2 == nullptr)
        return nullptr;
    if(pHead1 == nullptr)
        return pHead2;
    if(pHead2 == nullptr)
        return pHead1;
    
    ListNode* finalList = nullptr;

    if(pHead1->m_nValue < pHead2->m_nValue){

        finalList = pHead1;
        finalList->m_pNext = mergeList(pHead1->m_pNext, pHead2);
    }
    else{
        finalList = pHead2;
        finalList->m_pNext = mergeList(pHead1, pHead2->m_pNext);
    }

    return finalList;
}

int main(){

    // 链表中有重复的节点，正常运行
    ListNode* node1 = CreateListNode(1);
    ListNode* node2 = CreateListNode(2);
    ListNode* node3 = CreateListNode(3);
    ListNode* node4 = CreateListNode(2);
    ListNode* node5 = CreateListNode(5);
    ListNode* node6 = CreateListNode(6);
    ListNode* node7 = CreateListNode(7);
    ListNode* node8 = CreateListNode(8);

    ConnectListNodes(node1, node3);
    ConnectListNodes(node3, node5);
    ConnectListNodes(node5, node7);

    ConnectListNodes(node2, node4);
    ConnectListNodes(node4, node6);
    ConnectListNodes(node6, node8);

    PrintList(node1);
    PrintList(node2);

    ListNode* result = mergeList(node1, node2);
    PrintList(result);

    return 0;

}