// Source : https://oj.leetcode.com/problems/reverse-integer/
// Author : Robin Chen
// Date   : 2017.11.22

/********************************************************************************** 
* 
* Reverse digits of an integer.
* 
* Example1: x =  123, return  321
* Example2: x = -123, return -321
* 
* 
* Assume we are dealing with an environment which could only hold integers within 
* the 32-bit signed integer range. For the purpose of this problem, assume that your 
* function returns 0 when the reversed integer overflows.
*               
**********************************************************************************/

// 很简单，结果乘10加模10，原数除10
// 主要难点在于越界
// 实际上有个东西叫做INT_MAX，然而我直接用214748365暴力破解了

class Solution {
public:
    int reverse(int x) {
        int r = 0;
        while (x/10 != 0)
        {
            r = r*10 + x%10;
            x = x/10;
        }
        if(abs(r) >= 214748365)
            return 0;
        r = r*10 + x%10;
        return r;
    }
};

// Status: Accepted
// Runtime: 15 ms
// 98.31%