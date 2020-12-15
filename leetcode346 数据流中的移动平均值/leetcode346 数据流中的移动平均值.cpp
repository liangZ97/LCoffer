#include<iostream>
#include<queue>
using namespace std;
/*
给定一个整数数据流和一个窗口大小，根据该滑动窗口的大小，计算其所有整数的移动平均值。
MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3
*/

//头文件
class MovingAverage {
    int size;
    queue<int> qu;
    double windowSum = 0;
public:
    MovingAverage(int size) {
        this->size = size;
    }
    double next(int val) {
        qu.push(val);
        int len = qu.size();
        if (len <= size) {
            windowSum += val;
            return windowSum * 1.0 / len;
        }
        else {
            windowSum -= qu.front();
            qu.pop();
            windowSum += qu.back();
            return windowSum * 1.0 / size;
        }
    }
};
