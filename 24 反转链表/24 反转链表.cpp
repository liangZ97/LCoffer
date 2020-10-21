#include<iostream>
#include<memory>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*
定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) 
            return head;
        ListNode* prev = nullptr, * curr = head;
        while (curr)
        {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};
//int main() {
//    //int n = 1;
//    //int n = 2;
//    //vector<int> v = Solution().printNumbers(n);
//    //for (int j : v)
//        //cout << j << " ";
//    cout <<"hello cpp"<< endl;
//    return 0;
//}
