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
		// 特殊情况判断，如果只有一位且是0，就返回另一个链表（也可不做这个判断）
		if (l1->val == 0 && !l1->next) return l2;
		if (l2->val == 0 && !l2->next) return l1;

		ListNode* dummyHead = new ListNode(10086); // 添加一个虚拟头结点，赋值10086～
		ListNode* pointer = dummyHead; // 创造一个工作指针，指向新添加的头结点
		int carry = 0; // carry表示进位
		while (l1 || l2)
		{
			int v1 = l1 ? l1->val : 0; // 如果l1非空，让v1=l1->val，否则等于0
			int v2 = l2 ? l2->val : 0;
			int sum = v1 + v2 + carry;
			carry = sum / 10;
			pointer->next = new ListNode(sum % 10);
			pointer = pointer->next;
			if (l1) l1 = l1->next;
			if (l2) l2 = l2->next;
		}
		// 如果到了最后carry不是0，说明最后一位相加之后还有进位，再添加一个新的结点
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