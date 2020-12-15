#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) :val(x), next(NULL) {}
};
/*
����һ�������ж��������Ƿ��л���
�����������ĳ���ڵ㣬����ͨ���������� next ָ���ٴε���������д��ڻ��� 
Ϊ�˱�ʾ���������еĻ�������ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ����
��� pos �� -1�����ڸ�������û�л���ע�⣺pos ����Ϊ�������д��ݣ�������Ϊ�˱�ʶ�����ʵ�������
��������д��ڻ����򷵻� true �� ���򣬷��� false ��
*/
class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (!head) return false;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {//��֤���Կ�ָ���������
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) return true;
        }
        return false;
    }
};
//���Ҫ�ҵ������ڵ㣬��Ҫ֪�����ǣ���ָ���ƶ��ľ�����ԶΪ��ָ���2��
//����  2(X+Y)=X+Y+n(Z+Y)   X=(n-1)(Y+Z)+Z  n>=1
//��Ҳ����ζ�ţ�����������ʱ����������ֱ�������ָ��
//һ����ͷ�ڵ������һ�����������������ٴ��������ǻ������
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (!head) return head;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {//��֤���Կ�ָ���������
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) {
                ListNode* index1 = head;
                ListNode* index2 = fast;
                while (index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index1;
            }
        }
        return nullptr;
    }
};