#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*
��ת��λ�� m �� n ��������ʹ��һ��ɨ����ɷ�ת��1 �� m �� n �� �����ȡ�
����: 1->2->3->4->5->NULL, m = 2, n = 4
���: 1->4->3->2->5->NULL
*/

//���õݹ飬�����Ƿ�ת��������
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //�ݹ鲻Ҫ����ȥ��������һ���������һ��״̬�Ϳ���
        //���ȣ�ȷ���ݹ�Ľ�������,��˵��쳣�������ж�
        if (!head || !head->next)
            return head;
        //���Ҹ��ݺ������壬reverse �����᷵�ط�ת֮���ͷ��㣬�����ñ��� last ������
        ListNode* last = reverseList(head->next);
        //��������
        head->next->next = head;
        head->next = nullptr;
        return last;
    }

    //�������ǰ n ���ڵ㷴ת��n <= �����ȣ�
    ListNode* backNext = nullptr;
    ListNode* reverseN(ListNode* head, int n) {
        //���ڵ�һ���ڵ㣬��תn֮ǰ�ڵ㣬���ڵ�n���ڵ㷵�ر�������¼�����ڵ�
        if (n == 1) {
            backNext = head->next;
            return head;
        }
        ListNode* last = reverseN(head->next, n - 1);
        head->next->next = head;
        head->next = backNext;
        return last;
    }

    //��M��N֮��Ľڵ㷴ת
    ListNode* reverseBetweenMandN(ListNode* head, int m, int n) {
        if (m == 1)
            return reverseN(head, n);
        //����m֮ǰ�ĵݹ���ɺ���Ȼ�� head->next=head->next
        head->next=reverseBetweenMandN(head->next, m - 1, n - 1);
        return head;
    }
};