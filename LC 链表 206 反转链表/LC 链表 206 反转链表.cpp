#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) :val(x), next(NULL) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
/*
反转一个单链表。
示例:
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //递归
        if (!head || !head->next)
            return head;
        ListNode* last = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //双指针
        if (!head || !head->next)
            return head;
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur) {
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};