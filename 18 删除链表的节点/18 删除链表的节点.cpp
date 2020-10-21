#include<iostream>
#include<vector>
#include<deque>
using namespace std;
/*
给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。
返回删除后的链表的头节点。
输入: head = [4,5,1,9], val = 5
输出: [4,1,9]
解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
*/
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if (!head) return head;
        if (head->val == val) return head->next;
        ListNode* p = head;
        while (p != NULL) {
            if (p->next->val == val) break;
            p = p->next;
        }
        if (!p)
            return head;
        p->next = p->next->next;
        return head;
    }
};
class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        else {
            ListNode* front = head;
            deque<int> v;
            while (front != NULL) {
                v.push_front(front->val);
                front = front->next;
            }
            for (auto it = v.begin(); it != v.end(); it++) {
                head->val = *it;
                head = head->next;
            }
        }
        return head;
    }
};
