#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*
反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。1 ≤ m ≤ n ≤ 链表长度。
输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL
*/

//利用递归，首先是反转整个链表
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //递归不要跳进去，分析第一个或者最后一个状态就可以
        //首先，确定递归的结束条件,兼顾到异常的条件判断
        if (!head || !head->next)
            return head;
        //并且根据函数定义，reverse 函数会返回反转之后的头结点，我们用变量 last 接收了
        ListNode* last = reverseList(head->next);
        //单步处理
        head->next->next = head;
        head->next = nullptr;
        return last;
    }

    //将链表的前 n 个节点反转（n <= 链表长度）
    ListNode* backNext = nullptr;
    ListNode* reverseN(ListNode* head, int n) {
        //对于第一个节点，反转n之前节点，对于第n个节点返回本身，并记录后驱节点
        if (n == 1) {
            backNext = head->next;
            return head;
        }
        ListNode* last = reverseN(head->next, n - 1);
        head->next->next = head;
        head->next = backNext;
        return last;
    }

    //将M和N之间的节点反转
    ListNode* reverseBetweenMandN(ListNode* head, int m, int n) {
        if (m == 1)
            return reverseN(head, n);
        //对于m之前的递归完成后依然是 head->next=head->next
        head->next=reverseBetweenMandN(head->next, m - 1, n - 1);
        return head;
    }
};