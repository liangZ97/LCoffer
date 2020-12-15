#include<iostream>
#include<queue>
using namespace std;
/*
����һ��������������һ�����ڴ�С�����ݸû������ڵĴ�С�������������������ƶ�ƽ��ֵ��
MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3
*/

//ͷ�ļ�
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
