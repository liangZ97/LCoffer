#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        stack<int>  s;
        vector<int> v;
        while (head != nullptr) {
            s.push(head->val);
            head = head->next;
        }
        while (!s.empty()) {
            v.push_back(s.top());
            s.pop();
        }
        return v;
    }
};
class Solution1 {
public:
    vector<int> reversePrint(ListNode* head) {
        //反转数组
        vector<int> v;
        while (head) {
            v.push_back(head->val);
            head = head->next;
        }
        reverse(v.begin(), v.end());
        return v;
    }
};