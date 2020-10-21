#include<iostream>
#include<queue>
#include<deque>
using namespace std;
/*
请定义一个队列并实现函数 max_value 得到队列里的最大值，
要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。
若队列为空，pop_front 和 max_value 需要返回 -1
["MaxQueue","push_back","push_back","max_value","pop_front","max_value"]
      [[],  [1], [2], [],[],[]]
输出: [null,null,null, 2, 1, 2]
*/
//普通队列是这样的
//时间复杂度：O(1)（插入，删除），O(n)（求最大值）。
//插入与删除只需要普通的队列操作，为 O(1)，求最大值需要遍历当前的整个队列，最坏情况下为 O(n)。
//这样子也就要维护一个头部是最大值的双端队列
class MaxQueue {
    deque<int> deq;
    queue<int> que;
public:
    //这样子也就要维护一个头部是最大值的双端队列
    MaxQueue() {
    }
    //max_value 得到队列里的最大值
    int max_value() {
        if (que.empty()) return -1;
        return deq.front();
    }
    //尾插和头出的思路参考滑动窗口最大值
    //尾插
    void push_back(int value) {
        que.push(value);
        while (!deq.empty() && deq.back() < value) deq.pop_back();
        deq.push_back(value);
    }
    //头出
    int pop_front() {
        if (que.empty()) return -1;
        int PopVaule;
        PopVaule = que.front();
        if (!deq.empty() && deq.front() == PopVaule) deq.pop_front();
        que.pop();
        return PopVaule;
    }
};
