// https://leetcode.com/problems/divide-two-integers/
// Author : Robin Chen
// Date   : 2020.05.06

/********************************************************************************** 
* 
* Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
*
* Return the quotient after dividing dividend by divisor.
*
* The integer division should truncate toward zero, which means losing its fractional part. 
* For example, truncate(8.345) = 8 and truncate(-2.7335) = -2.
*               
**********************************************************************************/

// 思路 1
// 就是按加法做除法，要想快就要按指数级增加
// 也就是商和当前结果每次乘 2
// 于是想到用递归做，也就是超过被除数之后的残差再放进函数里
// 大部分时间都在处理溢出问题
// 经过不断的试错，决定包装一个负数的除法运算，因为负部比正部多一位
// 再把除数为 1 包装一下

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0)
            return 0;
        if (divisor == 1)
            return dividend;
        bool negative = false;
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)){
            negative = true;
        }

        int quotient = negDivide(nabs(dividend), nabs(divisor));
        if (negative)
            return -quotient;
        else
            return quotient;
    }
    
    int nabs(int a){
        return a < 0 ? a : -a;
    }
    
    int negDivide(int dividend, int divisor){
        if (dividend > divisor){
            return 0;
        }
        long quotient = 1;
        long curRes = divisor;
        while(curRes + curRes > dividend){
            curRes = curRes + curRes;
            quotient = quotient + quotient;
        }
        if (curRes == dividend){
            return quotient;
        }
        else
            quotient = quotient + negDivide(dividend - curRes, divisor);
        if (quotient > INT_MAX)
            return INT_MAX;
        else
            return quotient;
    }

};

// Success
// Runtime: 4 ms, faster than 64.60% of C++ online submissions for Divide Two Integers.
// Memory Usage: 5.8 MB, less than 100.00% of C++ online submissions for Divide Two Integers.

/**********************************************************************************/

// 抄网上的思路
// 用移位做，速度非常快，不用搜索多次

class Solution {
public:
    int divide(int dividend, int divisor) {
        if ( divisor == 0 )
            return INT_MAX;
        if( dividend == 0 )
            return 0;
        if( divisor == 1 )
            return dividend;
        if( divisor  == -1 )
            return (dividend == INT_MIN ) ? INT_MAX : -dividend;
        int negate = divisor > 0 ^ dividend > 0 ? 1 : 0;
        long divid= abs((long)dividend);
        long diviso = abs((long)divisor);
        int r = 0 ;
        for ( int i = 31; i>=0 && divid>=diviso ; i-- )
        {
            if( divid >= diviso<<i )
            {
                r|=1<<i;
                divid -= diviso<<i;
            }
        }
        if( negate )
            return -r;
        return r;
    }
};

// Success
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Divide Two Integers.
// Memory Usage: 5.8 MB, less than 100.00% of C++ online submissions for Divide Two Integers.