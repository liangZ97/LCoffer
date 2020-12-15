#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) :val(x), next(NULL) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
/*
����һ�������������е������ڵ��ż���ڵ�ֱ�����һ��
��ע�⣬����������ڵ��ż���ڵ�ָ���ǽڵ��ŵ���ż�ԣ������ǽڵ��ֵ����ż�ԡ�
�볢��ʹ��ԭ���㷨��ɡ�����㷨�Ŀռ临�Ӷ�ӦΪ O(1)��ʱ�临�Ӷ�ӦΪ O(nodes)��nodes Ϊ�ڵ�������
����: 1->2->3->4->5->NULL
���: 1->3->5->2->4->NULL
*/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return head;
        ListNode* evenHead = head->next;
        ListNode* even = evenHead;
        ListNode* odd = head;
        //��even�����һ������evenΪ��ʱ�����
        while (even!=nullptr && even->next != nullptr) {
            odd->next = even->next;
            odd = odd->next;
            even->next= odd->next;
            even = even->next;
        }
        //ƴ������
        odd->next = evenHead;
        return head;
    }
};

