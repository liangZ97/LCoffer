#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) :val(x), next(NULL) {}
};
/*
给出两个 非空 的链表用来表示两个非负的整数。
其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2)
            return nullptr;
        if (!l1 || !l2) 
            return l1 ? l1 : l2;
        // if (l1->val == 0 && l2)
        //     return l2;
        // if (l2->val == 0 && l1)
        //     return l1;
        ListNode* dummy = new ListNode(0);
        ListNode* res = dummy;
        int carry = 0;
        while (l1 || l2 || carry) {
            int num1 = l1 ? l1->val : 0;
            int num2 = l2 ? l2->val : 0;
            int numSum = num1 + num2 + carry;
            dummy->next = new ListNode(numSum % 10);
            carry = numSum / 10;
            dummy = dummy->next;
            if(l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        //if (carry)
        //    dummy->next = new ListNode(1);
        auto tem = res;
        res = res->next;
        delete tem;
        return res;
    }
};

//递归
class Solution {
    ListNode* dfs(ListNode* l1, ListNode* l2, int carry) {
        if (!l1 && !l2 && !carry)
            return nullptr;
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
        ListNode* head = new ListNode(sum % 10);
        head->next = dfs(l1 ? l1->next : nullptr, l2 ? l2->next : nullptr, sum / 10);
        return head;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2)
            return nullptr;
        if (!l1 || !l2)
            return l1 ? l1 : l2;
        return dfs(l1, l2, 0);
    }
};
