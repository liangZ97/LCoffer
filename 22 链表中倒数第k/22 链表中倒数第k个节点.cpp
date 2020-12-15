#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*
输入一个链表，输出该链表中倒数第k个节点。
为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。
例如，一个链表有6个节点，从头节点开始，它们的值依次是1、2、3、4、5、6。
这个链表的倒数第3个节点是值为4的节点

测试：给定一个链表: 1->2->3->4->5, 和 k = 2.
      返回链表 4->5.
*/
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* fast = head;
        ListNode* slow = head;
        //排除意外情况
        if (!head || !k) return NULL;
        //倒数第n个，快慢指针的距离为k-1
        //for (int i = 0; i < k - 1; i++) {
        //    //保证链表要有k个节点
        //    if (fast) fast = fast->next;
        //    else return NULL;
        //}
        //此时要保证fsat停留在最后一个节点上，不要继续移动
        //while (fast->next) {//当fast->next==NULL 此时fast和slow指向最后一个节点
        //    fast = fast->next;
        //    slow = slow->next;
        //}
        //或者这样子写
        for (int i = 0; i < k; i++) {
            //保证链表要有k个节点
            if (fast) fast = fast->next;
            else return NULL;
        }
        while (fast) {//当fast->next==NULL 此时fast和slow指向最后一个节点
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};

//当一个链表有环时，快慢指针都会陷入环中进行无限次移动，然后变成了追及问题。
//想象一下在操场跑步的场景，只要一直跑下去，快的总会追上慢的。
//当两个指针都进入环后，每轮移动使得慢指针到快指针的距离增加一，
//同时快指针到慢指针的距离也减少一，只要一直移动下去，快指针总会追上慢指针。
//链表总结
/*
#include <bits/stdc++.h>

using namespace std;

//定义一个结点模板
template<typename T>
struct Node {
	T data;
	Node *next;
	Node() : next(nullptr) {}
	Node(const T &d) : data(d), next(nullptr) {}
};

//删除 p 结点后面的元素
template<typename T>
void Remove(Node<T> *p) {
	if (p == nullptr || p->next == nullptr) {
		return;
	}
	auto tmp = p->next->next;
	delete p->next;
	p->next = tmp;
}

//在 p 结点后面插入元素
template<typename T>
void Insert(Node<T> *p, const T &data) {
	auto tmp = new Node<T>(data);
	tmp->next = p->next;
	p->next = tmp;
}

//遍历链表
template<typename T, typename V>
void Walk(Node<T> *p, const V &vistor) {
	while(p != nullptr) {
		vistor(p);
		p = p->next;
	}
}

int main() {
	auto p = new Node<int>(1);
	Insert(p, 2);
	int sum = 0;
	Walk(p, [&sum](const Node<int> *p) -> void { sum += p->data; });
	cout << sum << endl;
	Remove(p);
	sum = 0;
	Walk(p, [&sum](const Node<int> *p) -> void { sum += p->data; });
	cout << sum << endl;
	return 0;
}
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        ListNode* first = head;
        ListNode* second = dummy;
        for (int i = 0; i < n; ++i) {
            first = first->next;
        }
        while (first) {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};
