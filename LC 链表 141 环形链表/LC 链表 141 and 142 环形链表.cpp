#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) :val(x), next(NULL) {}
};
/*
给定一个链表，判断链表中是否有环。
如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 
为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。
如果链表中存在环，则返回 true 。 否则，返回 false 。
*/
class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (!head) return false;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {//保证不对空指针进行引用
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) return true;
        }
        return false;
    }
};
//如果要找到相遇节点，需要知道的是：快指针移动的距离永远为慢指针的2倍
//即有  2(X+Y)=X+Y+n(Z+Y)   X=(n-1)(Y+Z)+Z  n>=1
//这也就意味着，当二者相遇时。从相遇点分别定义两个指针
//一个从头节点出发，一个从相遇结点出发。再次相遇即是环形入口
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (!head) return head;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {//保证不对空指针进行引用
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