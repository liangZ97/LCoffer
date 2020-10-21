/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#pragma once
#include <vector>
#include <exception>

using namespace std;


// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		// ��������жϣ����ֻ��һλ����0���ͷ�����һ������Ҳ�ɲ�������жϣ�
		if (l1->val == 0 && !l1->next) return l2;
		if (l2->val == 0 && !l2->next) return l1;

		ListNode* dummyHead = new ListNode(10086); // ���һ������ͷ��㣬��ֵ10086��
		ListNode* pointer = dummyHead; // ����һ������ָ�룬ָ������ӵ�ͷ���
		int carry = 0; // carry��ʾ��λ
		while (l1 || l2)
		{
			int v1 = l1 ? l1->val : 0; // ���l1�ǿգ���v1=l1->val���������0
			int v2 = l2 ? l2->val : 0;
			int sum = v1 + v2 + carry;
			carry = sum / 10;
			pointer->next = new ListNode(sum % 10);
			pointer = pointer->next;
			if (l1) l1 = l1->next;
			if (l2) l2 = l2->next;
		}
		// ����������carry����0��˵�����һλ���֮���н�λ�������һ���µĽ��
		if (carry) pointer->next = new ListNode(1);
		return dummyHead->next;
	}
};

/*
int main() {
	ListNode l1(2,NULL);
	ListNode l2(3, NULL);


	return 0;
}

*/