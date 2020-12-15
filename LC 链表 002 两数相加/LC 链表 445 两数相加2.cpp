#include<iostream>
#include<stack>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) :val(x), next(NULL) {}
};
/*
�������� �ǿ� ���������������Ǹ��������������λλ������ʼλ�á�
���ǵ�ÿ���ڵ�ֻ�洢һλ���֡�����������ӻ᷵��һ���µ�����
����Լ���������� 0 ֮�⣬���������ֶ��������㿪ͷ��
���ף���������������޸ĸ���δ������仰˵���㲻�ܶ��б��еĽڵ���з�ת��
ʾ�������룺(7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
      �����7 -> 8 -> 0 -> 7
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        ListNode* ans = nullptr;
        while (!s1.empty() or !s2.empty() or carry != 0) {
            int a = s1.empty() ? 0 : s1.top();
            int b = s2.empty() ? 0 : s2.top();
            if (!s1.empty()) s1.pop();
            if (!s2.empty()) s2.pop();
            int cur = a + b + carry;
            carry = cur / 10;
            cur %= 10;
            auto curnode = new ListNode(cur);
            curnode->next = ans;
            ans = curnode;
        }
        return ans;
    }
};


//class Solution {
//    int length(ListNode* head) {
//        if (!head)
//            return 0;
//        return 1 + length(head->next);
//    }
//    int dfs(ListNode* l1, ListNode* l2, int depth,int len1,int len2) {
//        if (!l1)
//            return 0;
//        int carry = 0;
//        bool aligned = depth + len2 >= len1;
//        carry = dfs(l1->next, aligned ? l2->next : nullptr, depth + 1, len1, len2);
//        int sum = l1->val + (aligned ? l2->val : 0) + carry;
//        carry = sum / 10;
//        return carry;
//    }
//public:
//    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//        //�Ӻ���ӣ���һ�������Ե�˼·����ʹ�õݹ�
//        if (!l1 && !l2)
//            return nullptr;
//        if (!l1 || !l2)
//            return l1 ? l1 : l2;
//        int len1 = length(l1);
//        int len2 = length(l2);
//        if (len1 < len2)
//            swap(l1, l2);
//        if (dfs(l1, l2, 0, len1, len2)) {
//            ListNode* head = new ListNode(1);
//            head->next = l1;
//            l1 = head;
//        }
//        return l1;
//    }
//};
//
//
//int helper(ListNode* l1, ListNode* l2, int i, int n1, int n2) {
//
//    if (l1 == nullptr) return 0;
//    int add = 0;
//    bool aligned = i + n2 > n1; //��ǰ�ݹ����+�������ȴ��ڳ������ȣ�˵�������ˡ�
//    add = helper(l1->next, (aligned ? l2->next : l2), i + 1, n1, n2);
//    int sum = l1->val + (aligned ? l2->val : 0) + add;
//    l1->val = sum % 10;
//    return sum / 10;
//}