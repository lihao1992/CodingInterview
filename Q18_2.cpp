/*删除链表中重复的节点*/

#include<iostream>
#include "utils/list.h"

using namespace std;

void deleteDuplication(ListNode** pHead){

    // why ? ? ?
    if(pHead == nullptr || *pHead == nullptr)
        return ;
    
    // 声明一个到目前为止不是重复的节点
    ListNode* preNode = nullptr;
    ListNode* node = *pHead;

    while(node != nullptr){

        ListNode* next = node->m_pNext;
        bool tobeDelete = false;

        if(next != nullptr && next->m_nValue == node->m_nValue){

            tobeDelete = true;
        }
        // 如果没有重复的，链表正常向后遍历
        if(!tobeDelete){

            preNode = node;
            node = node->m_pNext;
        }

        else{

            ListNode* tobeDel = node;
            int value = node->m_nValue;

            // 删除重复的节点！
            while(tobeDel != nullptr && tobeDel->m_nValue == value){

                next = tobeDel->m_pNext;

                delete tobeDel;
                tobeDel = nullptr;

                tobeDel = next;
            }
            
            // 如果链表从一开始就有重复的节点，那么第一个不为重复的节点作为头结点
            if(preNode == nullptr)
                *pHead = next;
            
            else{
                preNode->m_pNext = next;
            }
            node = next;

        }
    }
}

int main(){

    ListNode* node1 = CreateListNode(1);
    ListNode* node2 = CreateListNode(2);
    ListNode* node3 = CreateListNode(2);
    ListNode* node4 = CreateListNode(4);
    ListNode* node5 = CreateListNode(5);
    ListNode* node6 = CreateListNode(5);

    ConnectListNodes(node1, node2);
    ConnectListNodes(node2, node3);
    ConnectListNodes(node3, node4);
    ConnectListNodes(node4, node5);
    ConnectListNodes(node5, node6);

    PrintList(node1);

    deleteDuplication(&node1);

    PrintList(node1);

    return 0;

}