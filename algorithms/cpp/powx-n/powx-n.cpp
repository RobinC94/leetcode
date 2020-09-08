// Source : https://leetcode.com/problems/powx-n/
// Author : Robin Chen
// Date   : 2020.09.08

/********************************************************************************** 
* 
* Implement pow(x, n), which calculates x raised to the power n (i.e. x^n).
* 
* Constraints:
* -100.0 < x < 100.0
* -2^31 <= n <= 2^31-1
* -10^4 <= xn <= 10^4           
**********************************************************************************/

// 初步思路：
// 找到最大的比 n 小的 2 的幂，剩下的部分乘

class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0)
            return 1 / myPow(x, -n);
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        double ori_x = x;
        int count = 1;
        while (count * 2 < n){
            count *= 2;      
            x *= x;
        }
        if (count == n)
            return x;
        return x * myPow(ori_x, n-count);
    }
};

// Status: Runtime Error
// 失败原因：INTMAX

/**********************************************************************************/

// 新思路：
// return res * x ^ n
// res 保存 n 为奇数时的余量

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 1)
            return x;
        if (n < 0){
            if (n == INT_MIN)
                return 1 / (myPow(x, INT_MAX) * x);
            return 1 / myPow(x, -n);
        }
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        double res = 1;
        while (n > 1){
            if (n % 2 == 0){
                x = x * x;
                n = n / 2;
            }
            else{
                res = res * x;
                x = x * x;
                n = n / 2;
            }
        }
        return res * x;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Pow(x, n).
// Memory Usage: 5.9 MB, less than 90.09% of C++ online submissions for Pow(x, n).
