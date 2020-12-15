#include<iostream>
//#include<queue>
//#include<unordered_map>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) :val(x), next(NULL) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
/*
给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
示例 1:
输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL
*/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        //观察发现，移动k个位置，其实就是将倒数第k个节点作为head，然后将链表末尾重新接住
        //也就是说，将链表构造成环状链表，然后在倒数第k个位置处断开
        //为了构造next，我们需要找到倒数第k+1个节点，对其进行操作

        if (!head) return head;//必须进行异常判断，否则会除0异常
        //为了避免重复计算，我们对k取模
        int l = 0;
        ListNode* cur = head;
        while (cur) {
            ++l;
            cur = cur->next;
        }
        k = k % l;
        //用快慢指针找到倒数第K+1个节点
        ListNode* fast = head;
        ListNode* slow = head;
        for (int i = 0; i < k; ++i)
            fast = fast->next;
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        fast->next = head;
        head = slow->next;
        slow->next = nullptr;
        return head;
    }
};