#include<iostream>
using namespace std;
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
/*
多级双向链表中，除了指向下一个节点和前一个节点指针之外，
它还有一个子链表指针，可能指向单独的双向链表。
这些子列表也可能会有一个或多个自己的子项，依此类推，生成多级数据结构，如下面的示例所示。
给你位于列表第一级的头节点，请你扁平化列表，使所有结点出现在单级双链表中。
https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/multilevellinkedlist.png
https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/multilevellinkedlistflattened.png
*/

class Solution {
public:
    Node* flatten(Node* head) {
        //遍历链表，找到child不为空的节点A
        //创建新的节点来记录A的next节点C
        //将A的子节点B接到A的next节点中，继续遍历，直到为null
        //将存下的节点C接到null之前的节点后
        Node* cur = head;
        Node* Next = nullptr;
        while (cur != nullptr) {
            if (cur->child != nullptr) {
                Next = cur->next;
                cur->next = cur->child;
                cur->child->prev = cur;
                cur->child = nullptr;
                flatten(cur->next);
                while (cur->next != nullptr) 
                    cur = cur->next;
                if (cur != nullptr && Next != nullptr) {
                    cur->next = Next;
                    Next->prev = cur;
                }
            }
            else
                cur = cur->next;
        }
        return head;
    }
};

