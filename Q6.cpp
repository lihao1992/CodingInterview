/*从尾到头（逆序）打印链表*/

#include<iostream>
#include<vector>
#include<stack>
#include "utils/list.h"

using namespace std;
/*
struct ListNode{

    int value;
    ListNode* p_next;
};
*/

void PrintListByReverse(ListNode* pHead){

    // use stack to store list node from start to end, then pop tail to head, implement reverse print list
    stack<ListNode*>nodes;

    ListNode* pNode = pHead;
    while(pNode != nullptr){

        // 入栈
        nodes.push(pNode);
        // 当前节点存入栈中，然后遍历下一个链表节点
        pNode = pNode->m_pNext;
    }

    // 将链表全部遍历存入栈中，然后我们要打印了，也就是出栈！
    while(!nodes.empty()){

        pNode  = nodes.top();
        cout << pNode->m_nValue << endl;
        // 出栈后，释放栈首元素
        nodes.pop();
    }
}

int main(){

    // 创建链表
    ListNode* node1 = CreateListNode(1);
    ListNode* node2 = CreateListNode(2);
    ListNode* node3 = CreateListNode(3);
    ListNode* node4 = CreateListNode(4);
    ListNode* node5 = CreateListNode(5);

    // 链接链表
    ConnectListNodes(node1, node2);
    ConnectListNodes(node2, node3);
    ConnectListNodes(node3, node4);
    ConnectListNodes(node4, node5);

    PrintList(node1);
    PrintListByReverse(node1);

    return 0;

}


// 练习
void reverselist(ListNode* pHead){

    // 要用栈，你得先定义栈啊
    stack<ListNode*> nodes;

    ListNode* pNode = pHead;
    while(pNode != nullptr){

        nodes.push(pNode);
        pNode = pNode->m_pNext;
    }

    while(!nodes.empty()){

        pNode = nodes.top();
        cout << pNode->m_nValue << endl;
        nodes.pop();
    }
}