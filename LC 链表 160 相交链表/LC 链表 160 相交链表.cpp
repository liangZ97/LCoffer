#include<iostream>
#include<unordered_set>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) :val(x), next(NULL) {}
};
/*
编写一个程序，找到两个单链表相交的起始节点。
输入：intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
输出：Reference of the node with value = 2
输入解释：相交节点的值为 2 （注意，如果两个链表相交则不能为 0）。
从各自的表头开始算起，链表 A 为 [0,9,1,2,4]，链表 B 为 [3,2,4]。
在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。
*/

class Solution {
public:
    //如果两个链表没有交点，返回 null.
    //在返回结果后，两个链表仍须保持原有的结构。
    //程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        //很明显可以想到时方法是利用一个hash数组判断时候重复出现
        if (!headA && !headB)
            return headA;
        if (!headA || !headB)
            return nullptr;
        unordered_set< ListNode*> hash;
        ListNode* cur = headA;
        while (cur) {
            hash.insert(cur);
            cur = cur->next;
        }
        cur = headB;
        while (cur) {
            if (hash.find(cur) != hash.end())
                return cur;
            cur = cur->next;
        }
        return nullptr;
    }
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        //利用双指针法，分别指向headA和headB，遍历完该数组即接着遍历另一个，相遇时就是相遇点
        //如果没有相遇点，那么会在nullptr处相遇，无论两者长度是否一致。
        if (!headA && !headB)
            return headA;
        if (!headA || !headB)
            return nullptr;
        ListNode* cur1 = headA;
        ListNode* cur2 = headB;
        while (cur1 != cur2) {
            cur1 = cur1 ? cur1->next : headB;
            cur2 = cur2 ? cur2->next : headA;
        }
        return cur1;
    }
};