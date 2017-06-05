/*两个链表的第一个公共节点*/
// 时间复杂度O(M+N)
#include<iostream>
#include "utils/list.h"

using namespace std;

int getlen(ListNode* pHead);

ListNode* firstSameNode(ListNode* pHead1, ListNode* pHead2){

    if(pHead1 == nullptr || pHead2 == nullptr)
        return nullptr;

    // 计算两个链表的长度,算出两个链表的长度差
    int len1 = getlen(pHead1);
    int len2 = getlen(pHead2);

    int lenDif = len1 - len2;

    ListNode* listLong = pHead1;
    ListNode* listShort = pHead2;

    if(len2>len1){
        listLong = pHead2;
        listShort = pHead1;
        
        lenDif = len2-len1;
    }

    // 长的那个链表先走lenDif步，然后两个链表一起向后走，并比较值大小
    for(int i = 0; i<lenDif; ++i){

        listLong = listLong->m_pNext;
    }

    while((listLong != nullptr) && (listShort != nullptr) && (listLong != listShort)){

        listLong = listLong->m_pNext;
        listShort = listShort->m_pNext;
    }

    // 第一个公共节点
    ListNode* result = listLong;

    return result;


}

int getlen(ListNode* pHead){

    int len = 0;
    ListNode* node = pHead;

    while(node != nullptr){

        ++len;
        node = node->m_pNext;
    }
    return len;
}

int main(){

    ListNode* node1 = CreateListNode(1);
    ListNode* node2 = CreateListNode(2);
    ListNode* node3 = CreateListNode(3);
    ListNode* node4 = CreateListNode(4);
    ListNode* node5 = CreateListNode(5);
    ListNode* node6 = CreateListNode(6);
    ListNode* node7 = CreateListNode(7);
    ListNode* node8 = CreateListNode(8);

    ConnectListNodes(node1, node2);
    ConnectListNodes(node2, node3);
    ConnectListNodes(node3, node6);
    ConnectListNodes(node6, node7);
    ConnectListNodes(node7, node8);

    ConnectListNodes(node4, node5);
    //ConnectListNodes(node5, node7);
    //ConnectListNodes(node7, node8);

    PrintList(node1);
    PrintList(node4);

    ListNode* result = firstSameNode(node4, node1);

    PrintListNode(result);

    return 0;
}