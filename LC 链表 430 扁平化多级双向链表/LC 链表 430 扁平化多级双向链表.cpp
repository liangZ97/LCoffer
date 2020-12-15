#include<iostream>
using namespace std;
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
/*
�༶˫�������У�����ָ����һ���ڵ��ǰһ���ڵ�ָ��֮�⣬
������һ��������ָ�룬����ָ�򵥶���˫������
��Щ���б�Ҳ���ܻ���һ�������Լ�������������ƣ����ɶ༶���ݽṹ���������ʾ����ʾ��
����λ���б��һ����ͷ�ڵ㣬�����ƽ���б�ʹ���н������ڵ���˫�����С�
https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/multilevellinkedlist.png
https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/multilevellinkedlistflattened.png
*/

class Solution {
public:
    Node* flatten(Node* head) {
        //���������ҵ�child��Ϊ�յĽڵ�A
        //�����µĽڵ�����¼A��next�ڵ�C
        //��A���ӽڵ�B�ӵ�A��next�ڵ��У�����������ֱ��Ϊnull
        //�����µĽڵ�C�ӵ�null֮ǰ�Ľڵ��
        Node* cur = head;
        Node* Next = nullptr;
        while (cur != nullptr) {
            if (cur->child != nullptr) {
                Next = cur->next;
                cur->next = cur->child;
                cur->child->prev = cur;
                cur->child = nullptr;
                flatten(cur->next);
                while (cur->next != nullptr) 
                    cur = cur->next;
                if (cur != nullptr && Next != nullptr) {
                    cur->next = Next;
                    Next->prev = cur;
                }
            }
            else
                cur = cur->next;
        }
        return head;
    }
};

