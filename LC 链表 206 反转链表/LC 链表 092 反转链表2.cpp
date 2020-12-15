#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) :val(x), next(NULL) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
/*
反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
说明:
1 ≤ m ≤ n ≤ 链表长度。
示例:
输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL
*/

class Solution {
    ListNode* successor = nullptr;
    ListNode* reverseN(ListNode* head, int n) {
        if (n == 1) {
            successor = head->next;
            return head;
        }
        ListNode* last = reverseN(head->next, n - 1);
        head->next->next = head;
        head = successor;
        return head;
    }
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head)
            return head;
        if (m == 1)
            return reverseN(head, n);
        head->next = reverseBetween(head->next, m - 1, n - 1);
        return head;
    }
};