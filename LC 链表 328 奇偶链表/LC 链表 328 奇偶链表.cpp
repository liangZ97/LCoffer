#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) :val(x), next(NULL) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
/*
给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。
请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。
请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。
输入: 1->2->3->4->5->NULL
输出: 1->3->5->2->4->NULL
*/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return head;
        ListNode* evenHead = head->next;
        ListNode* even = evenHead;
        ListNode* odd = head;
        //当even是最后一个或者even为空时候结束
        while (even!=nullptr && even->next != nullptr) {
            odd->next = even->next;
            odd = odd->next;
            even->next= odd->next;
            even = even->next;
        }
        //拼接起来
        odd->next = evenHead;
        return head;
    }
};

