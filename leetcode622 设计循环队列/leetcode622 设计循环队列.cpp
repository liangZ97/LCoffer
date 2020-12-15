#include<iostream>
#include<vector>
using namespace std;
/*
������ѭ������ʵ�֡� ѭ��������һ���������ݽṹ
��������ֻ��� FIFO���Ƚ��ȳ���ԭ���Ҷ�β�������ڶ���֮�����γ�һ��ѭ��
MyCircularQueue(k): �����������ö��г���Ϊ k ��
Front: �Ӷ��׻�ȡԪ�ء��������Ϊ�գ����� -1 ��
Rear: ��ȡ��βԪ�ء��������Ϊ�գ����� -1 ��
enQueue(value): ��ѭ�����в���һ��Ԫ�ء�����ɹ������򷵻��档
deQueue(): ��ѭ��������ɾ��һ��Ԫ�ء�����ɹ�ɾ���򷵻��档
isEmpty(): ���ѭ�������Ƿ�Ϊ�ա�
isFull(): ���ѭ�������Ƿ�������
*/

//�������������ǻ���һ��Ԫ�ؿռ���˷�
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

//����leetcode�Ĺ��췽ʽ
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
        //Ϊ��ͳһ�����ʽ
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
