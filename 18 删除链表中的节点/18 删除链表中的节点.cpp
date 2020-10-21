#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};
/*
˼·������������ʼ��p=head�����ǡ�
��p->val == valʱ��ɾ��p������p���������ͷ�ڵ㡣
��p->next->val ��= valʱ����������ֱ��p->next->val == valʱֹ��ɾ��p->next���ɡ�

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
