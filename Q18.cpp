/*链表中删除节点，要求O(1)时间复杂度*/
// 需要注意的是，该题的假设是已知待删除的节点确实在链表中，那么我们可以通过O(1)时间删除，
// 但是我们需要O(n)时间才能确定一个节点是否在链表中，我们假设调用该函数的使用者已经完成了查询操作 ！

#include<iostream>
#include "utils/list.h"

using namespace std;

// 注意是指向指针的指针,因为链表如果只有一个节点，并且要被删除的话/ 待删节点就是头结点
void deleteListNode(ListNode** pHead, ListNode* tobedelete){

    if(!pHead || !tobedelete)
        return ;
    
    // 待删除节点不是尾节点的话
    if(tobedelete->m_pNext != nullptr){

        // 用待删除的节点的下一节点替换待删节点，具体来说，我们可以在O(1)时间内查找到待删节点的下一节点，
        // 那么我们就将下一节点的值覆盖待删节点的值，然后删掉下一节点，就相当于我们删掉了待删节点
        ListNode* next = tobedelete->m_pNext;
        tobedelete->m_nValue = next->m_nValue;
        tobedelete->m_pNext = next->m_pNext;

        delete next;
        next = nullptr;
    }

    // 如果链表中只有一个节点，恰巧我们又要删除这个节点
    else if(*pHead == tobedelete){

        delete tobedelete;
        tobedelete = nullptr;

        // 链表的头结点也要设置成null
        *pHead = nullptr;
    }

    // 删除尾节点
    else{
        // 注意指针！
        ListNode* node = *pHead;
        while(node->m_pNext != tobedelete){

            node = node->m_pNext;
        }
        // 已到达尾节点前一节点
        node->m_pNext = nullptr;
        delete tobedelete;
        tobedelete = nullptr;
    }

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
    // 注意函数调用的时候，参数传递的形式
    deleteListNode(&node1, node4);
    PrintList(node1);
    deleteListNode(&node1, node4);
    PrintList(node1);
    // 删除空节点
    deleteListNode(nullptr, nullptr);

    return 0;
}