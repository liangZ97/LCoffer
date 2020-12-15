#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
/*
给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
要求返回这个链表的 深拷贝。 
我们用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 [val, random_index] 表示：
val：一个表示 Node.val 的整数。
random_index：随机指针指向的节点索引（范围从 0 到 n-1）；如果不指向任何节点，则为  null 。
*/

//DFS
class Solution {
    unordered_map<Node*, Node*> visited;
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return head;
        if (visited.find(head) != visited.end()) return visited[head];
        Node* newNode = new Node(head->val);
        visited[head] = newNode;
        newNode->random = copyRandomList(head->random);
        newNode->next = copyRandomList(head->next);
        return newNode;
    }
};

//BFS
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return head;
        queue< Node*> qu;
        unordered_map<Node*, Node*> visited;
        visited[head] = new Node(head->val);
        qu.push(head);
        while (!qu.empty()) {
            auto cur = qu.front();
            qu.pop();
            if(cur->next||cur->random){
                if (!cur->next) 
                    visited[cur]->next = nullptr;
                else {
                    if (visited.find(cur->next) == visited.end()) {
                        visited[cur->next] = new Node(cur->next->val);
                        qu.push(cur->next);
                    }
                    visited[cur]->next = visited[cur->next];
                }
                if (!cur->random)
                    visited[cur]->random = nullptr;
                else {
                    if (visited.find(cur->random) == visited.end()) {
                        visited[cur->random] = new Node(cur->random->val);
                        qu.push(cur->random);
                    }
                    visited[cur]->random = visited[cur->random];
                }
                
            }
        }
        return visited[head];
    }
};
