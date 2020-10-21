#include<iostream>
using namespace std;
/*
求 1+2+...+n ，要求不能使用
乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
输入: n = 3
输出: 6
*/

class Solution {
public:
    int sumNums(int n) {
        //1 <= n <= 10000
        //递归太奇妙了
        /*
        如果使用条件判断语句
        return n? n+sumNums(n-1):0;
        */

        //现在只有加减法，赋值，位运算符以及逻辑运算符。
        //利用 && 和 || 的短路效应进行递归
        n && (n += sumNums(n - 1));
        return n;
    }
};