#include<iostream>
#include<vector>
using namespace std;
/*
设计你的循环队列实现。 循环队列是一种线性数据结构
其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环
MyCircularQueue(k): 构造器，设置队列长度为 k 。
Front: 从队首获取元素。如果队列为空，返回 -1 。
Rear: 获取队尾元素。如果队列为空，返回 -1 。
enQueue(value): 向循环队列插入一个元素。如果成功插入则返回真。
deQueue(): 从循环队列中删除一个元素。如果成功删除则返回真。
isEmpty(): 检查循环队列是否为空。
isFull(): 检查循环队列是否已满。
*/

//按照王争，但是会有一个元素空间的浪费
class MyCircularQueue {
    int* data;
    int head;
    int tail;
    int capacity;
public:
    MyCircularQueue(int k) {
        data = new int[k + 1];
        capacity = k + 1;
        head = tail = 0;
    }

    bool enQueue(int value) {
        if (isFull())
            return false;
        data[tail] = value;
        tail = (tail + 1) % capacity;
    }

    bool deQueue() {
        if (isEmpty())
            return false;
        head = (head + 1) % capacity;
    }

    int Front() {
        if (isEmpty())
            return false;
        return data[head];
    }

    int Rear() {
        if (isEmpty())
            return false;
        return data[(tail - 1 + capacity) % capacity];
    }

    bool isEmpty() {
        return head == tail;
    }

    bool isFull() {
        return (tail + 1) % capacity == head;
    }
};

//按照leetcode的构造方式
class MyCircularQueue {
    int* data;
    int head;
    int tail;
    int capacity;
public:
    MyCircularQueue(int k) {
        data = new int[k];
        capacity = k;
        head = tail = -1;
    }

    bool enQueue(int value) {
        if (isFull())
            return false;
        if (isEmpty()) 
            head = 0;
        //为了统一表达形式
        tail = (tail + 1) % capacity;
        data[capacity] = value;
        return true;
    }

    bool deQueue() {
        if (isEmpty())
            return false;
        if (head == tail) {
            head = tail = -1;
            return true;
        }
        head= (head + 1) % capacity;
        return true;
    }

    int Front() {
        if (isEmpty())
            return -1;
        return data[head];
    }

    int Rear() {
        if (isEmpty())
            return -1;
        return data[tail];
    }

    bool isEmpty() {
        return head == -1;
    }

    bool isFull() {
        return (tail + 1) % capacity == head;
    }
};

int main() {
    MyCircularQueue* obj = new MyCircularQueue(3);
    bool param_1 = obj->enQueue(1);
    //param_1 = (param_1 == true);
    cout << param_1 << endl;
    bool param_2 = obj->enQueue(2);
    //param_2 = (param_2 == true);
    cout << param_2 << endl;
    bool param_3 = obj->enQueue(3);
    bool param_4 = obj->enQueue(4);
    int rear=obj->Rear();
    bool param_5 = obj->isFull();
    bool param_6 = obj->deQueue();
    bool param_7 = obj->enQueue(4);
    int rear1 = obj->Rear();
    cout << param_1 << param_2 << param_3 << param_4 << endl;
    cout << rear << endl;
    cout << param_5<< param_6<< param_7 << endl;
    cout << rear1 << endl;
    return 0;
}
