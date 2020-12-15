#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) :val(x), next(NULL) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
/*
请判断一个链表是否为回文链表。
示例 1:
输入: 1->2
输出: false
示例 2:
输入: 1->2->2->1
输出: true
进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
*/

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        //O(n) 时间复杂度和 O(1) 空间复杂度
        //代表一次遍历，并且使用若干个常量
        if (!head || !head->next)
            return true;
        vector< ListNode*> vec;
        while (head) {
            vec.emplace_back(head);
            head = head->next;
        }
        for (int i = 0, j = vec.size() - 1; i < j; ++i, --j) {
            if (vec[i]->val != vec[j]->val)
                return false;
        }
        return true;
        //执行用时：56 ms, 在所有 C++ 提交中击败了6.46 %的用户
        //内存消耗：15.3 MB, 在所有 C++ 提交中击败了7.12 %的用户
    }
};

//或者就是利用快慢指针找到中点，反转后面部分链表，再进行判断
class Solution {
    ListNode* reverseList(ListNode* head) {
        //双指针
        if (!head || !head->next)
            return head;
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur) {
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        //判断链表是奇数个还是偶数个
        if(fast)
            slow = slow->next;
        slow = reverseList(slow);
        while (slow) {
            if (slow->val != head->val)
                return false;
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
};