#include<iostream>
#include<memory>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*
����������������������ϲ�����������ʹ�������еĽڵ���Ȼ�ǵ�������ġ�
���룺1->2->4, 1->3->4
�����1->1->2->3->4->4
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //����һ���½��
        if (!l1) return l2;
        if (!l2) return l1;
        if (!l1 && !l2) return NULL;
        ListNode* head = new ListNode(INT_MAX);
        ListNode* result = head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                head->next = l1;
                l1 = l1->next;
            }
            else {
                head->next = l2;
                l2 = l2->next;

            }
            head = head->next;
        }
        head->next = l1 ? l1 : l2;
        return result->next;
    }
};

//int main() {
//    //int n = 1;
//    //int n = 2;
//    //vector<int> v = Solution().printNumbers(n);
//    //for (int j : v)
//        //cout << j << " ";
//    cout << "hello cpp" << endl;
//    return 0;
//}
