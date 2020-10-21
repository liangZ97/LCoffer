#include<iostream>
using namespace std;
/*
使用位运算的二进制数的相加过程：
1) 两个二进制数各位异或，得到无进位的和 
2) 二进制数各位与再左移，计算进位 
3) 无进位和与进位异或
重复上面操作，直到不再有进位，即进位为0。
*/
class Solution {
public:
    int add(int a, int b) {
        int sum = 0, carry = 0;
        while (b) {
            //如果a、b两个值不相同，则异或结果为1。如果a、b两个值相同，异或结果为0。
            sum = a ^ b;
            carry = (unsigned int)(a & b) << 1;
            a = sum;
            b = carry;
        }
        return a;
    }
};
class Solution1 {
public:
    int add(int a, int b) {
        return b ? add(a ^ b, (unsigned int)(a & b) << 1) : a;
    }
};
/*
相关问题：
 不使用新的变量，交换两个变量的值。比如有两个变量a、b，希望交换它们的值。有两种不同的操作：
 1. 基于加减法 -- a = a + b; b = a - b; a = a - b;
 2. 基于位运算 -- a = a ^ b; b = a ^ b; a = a ^ b;
*/
