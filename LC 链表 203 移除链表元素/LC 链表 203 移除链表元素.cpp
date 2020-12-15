#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) :val(x), next(NULL) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
/*
删除链表中等于给定值 val 的所有节点。
示例:
输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5
*/

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head)
            return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = head;
        while (fast) {
            if (fast->val == val) {
                ListNode* tem = fast;
                slow->next = fast->next;
                fast = fast->next;
                //slow = slow->next;
                delete tem;
            }
            else {
                fast = fast->next;
                slow = slow->next;
            }
        }
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head)
            return head;
        if (head->val == val) {
            head->next = removeElements(head->next, val);
            return head->next;
        }
        head->next = removeElements(head->next, val);
        return head;
    }
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head)
            return head;
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;
    }
};