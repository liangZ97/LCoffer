#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) :val(x), next(NULL) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
/*
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
示例：
给定一个链表: 1->2->3->4->5, 和 n = 2.
当删除了倒数第二个节点后，链表变为 1->2->3->5.
给定的 n 保证是有效的。
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //排除意外情况
        if (!head || !n) return NULL;
        ListNode* dummy = new ListNode(-1,head);
        //dummy->next = head;
        ListNode* fast = head;
        ListNode* slow = dummy;
        for (int i = 0; i < n; i++) {
            //保证链表要有n个节点
            if (fast) fast = fast->next;
            else return NULL;
        }
        while (fast) {
            //当fast->next==NULL slow指向倒数n+1个节点
            fast = fast->next;
            slow = slow->next;
        }
        auto temp = slow->next;
        slow->next = temp->next;
        ListNode* ans = dummy->next;
        delete temp;
        delete dummy;
        return ans;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //典型快慢指针 默认无 dummy
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head, * slow = head;
        for (int i = 0; i < n; i++)fast = fast->next;
        if (fast == NULL) {//删掉头结点
            fast = head->next;
            delete head;
            return fast;
        }
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        auto temp = slow->next;
        slow->next = temp->next;
        delete temp;
        return head;
    }
};

//递归
class Solution {
    int rev_idx = 0;
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return nullptr;
        head->next = removeNthFromEnd(head->next, n);
        rev_idx++;
        if (rev_idx == n) return head->next;
        return head;
    }
};
