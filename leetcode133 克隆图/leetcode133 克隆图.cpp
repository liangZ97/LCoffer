#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
/*
给你无向 连通 图中一个节点的引用，请你返回该图的 深拷贝（克隆）。
图中的每个节点都包含它的值 val（int） 和其邻居的列表（list[Node]）。
*/

//拷贝即构建一张与原图结构，值均一样的图，但是其中的节点不再是原来图节点的引用
//DFS
class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> visited;
        if (node == NULL)
            return node;
        if(visited.find(node) != visited.end())
        //if (visited.count(node))
            return visited[node];

        Node* cloneNode = new Node(node->val);
        visited.insert({ node,cloneNode });

        for (auto& nei : node->neighbors) {
            cloneNode->neighbors.emplace_back(cloneGraph(nei));
        }
        return cloneNode;
    }
};

//BFS
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL)
            return node;
        unordered_map<Node*, Node*> visited;
        queue< Node*> qu;
        qu.push(node);
        visited[node] = new Node(node->val);
        while (!qu.empty()) {
            Node* cur = qu.front();
            qu.pop();
            for (auto& nei : cur->neighbors) {
                if (visited.find(nei) == visited.end()) {
                    qu.push(nei);
                    visited[nei] = new Node(nei->val);
                }
                //visited[cur]->neighbors.emplace_back(nei);
                //上面那样的话,还是拷贝的原始的数据
                visited[cur]->neighbors.emplace_back(visited[nei]);
            }
        }
        return visited[node];
    }
};
