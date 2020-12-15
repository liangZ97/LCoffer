#include<iostream>
using namespace std;
/*
设计链表的实现。您可以选择使用单链表或双链表。
单链表中的节点应该具有两个属性：val 和 next。val 是当前节点的值，next 是指向下一个节点的指针/引用。
在链表类中实现这些功能：
get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val  的节点。
如果 index 等于链表的长度，则该节点将附加到链表的末尾。
如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。
*/

class MyLinkedList {
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) :val(x), next(NULL) {}
    };
    ListNode* node;
    size_t size;
public:
    MyLinkedList() {
        node = new ListNode(0);
        size = 0;
    }
    int get(int index) {
        if (index< 0 || index > (size - 1))
            return -1;
        ListNode* cur = node->next;
        while (index--)
            cur = cur->next;
        return cur->val;
    }
    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = node->next;
        node->next = newNode;
        ++size;
    }
    void addAtTail(int val) {
        ListNode* cur = node;
        while (cur->next)
            cur = cur->next;
        cur->next = new ListNode(val);
        ++size;

    }
    void addAtIndex(int index, int val) {
        if (index > size)
            return;
        ListNode* newNode = new ListNode(val);
        ListNode* cur = node;
        while (index--)
            cur = cur->next;
        newNode->next = cur->next;
        cur->next = newNode;
        ++size;
    }
    void deleteAtIndex(int index) {
        if (index< 0 || index > (size - 1))
            return ;
        ListNode* cur = node;
        while(index--)
            cur = cur->next;
        ListNode* tem = cur->next;
        cur->next = tem->next;
        --size;
        delete tem;
    }
};

