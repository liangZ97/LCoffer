#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) :val(x), next(NULL) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
/*
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //创建一个新结点
        if (!l1 && !l2) return NULL;
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode* head = new ListNode(INT_MAX);
        ListNode* result = head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                head->next = l1;
                l1 = l1->next;
            }
            else {
                head->next = l2;
                l2 = l2->next;

            }
            head = head->next;
        }
        head->next = l1 ? l1 : l2;
        auto tem = result;
        result = result->next;
        delete tem;
        return result;
    }
};