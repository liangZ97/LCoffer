#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*
����һ����������������е�����k���ڵ㡣
Ϊ�˷��ϴ�����˵�ϰ�ߣ������1��ʼ�������������β�ڵ��ǵ�����1���ڵ㡣
���磬һ��������6���ڵ㣬��ͷ�ڵ㿪ʼ�����ǵ�ֵ������1��2��3��4��5��6��
�������ĵ�����3���ڵ���ֵΪ4�Ľڵ�

���ԣ�����һ������: 1->2->3->4->5, �� k = 2.
      �������� 4->5.
*/
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* fast = head;
        ListNode* slow = head;
        //�ų��������
        if (!head || !k) return NULL;
        //������n��������ָ��ľ���Ϊk-1
        //for (int i = 0; i < k - 1; i++) {
        //    //��֤����Ҫ��k���ڵ�
        //    if (fast) fast = fast->next;
        //    else return NULL;
        //}
        //��ʱҪ��֤fsatͣ�������һ���ڵ��ϣ���Ҫ�����ƶ�
        //while (fast->next) {//��fast->next==NULL ��ʱfast��slowָ�����һ���ڵ�
        //    fast = fast->next;
        //    slow = slow->next;
        //}
        //����������д
        for (int i = 0; i < k; i++) {
            //��֤����Ҫ��k���ڵ�
            if (fast) fast = fast->next;
            else return NULL;
        }
        while (fast) {//��fast->next==NULL ��ʱfast��slowָ�����һ���ڵ�
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};

//��һ�������л�ʱ������ָ�붼�����뻷�н������޴��ƶ���Ȼ������׷�����⡣
//����һ���ڲٳ��ܲ��ĳ�����ֻҪһֱ����ȥ������ܻ�׷�����ġ�
//������ָ�붼���뻷��ÿ���ƶ�ʹ����ָ�뵽��ָ��ľ�������һ��
//ͬʱ��ָ�뵽��ָ��ľ���Ҳ����һ��ֻҪһֱ�ƶ���ȥ����ָ���ܻ�׷����ָ�롣
//�����ܽ�
/*
#include <bits/stdc++.h>

using namespace std;

//����һ�����ģ��
template<typename T>
struct Node {
	T data;
	Node *next;
	Node() : next(nullptr) {}
	Node(const T &d) : data(d), next(nullptr) {}
};

//ɾ�� p �������Ԫ��
template<typename T>
void Remove(Node<T> *p) {
	if (p == nullptr || p->next == nullptr) {
		return;
	}
	auto tmp = p->next->next;
	delete p->next;
	p->next = tmp;
}

//�� p ���������Ԫ��
template<typename T>
void Insert(Node<T> *p, const T &data) {
	auto tmp = new Node<T>(data);
	tmp->next = p->next;
	p->next = tmp;
}

//��������
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
