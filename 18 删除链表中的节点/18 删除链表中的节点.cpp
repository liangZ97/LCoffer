#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};
/*
思路：遍历链表，开始在p=head处考虑。
当p->val == val时，删除p，返回p后面的链表头节点。
当p->next->val ！= val时，向后遍历，直到p->next->val == val时止。删除p->next即可。

*/
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
