// https://leetcode.com/problems/largest-palindrome-product/
// Author : Robin Chen
// Date   : 2017.11.22

/********************************************************************************** 
* 
* Find the largest palindrome made from the product of two n-digit numbers.
* Since the result could be very large, you should return the largest palindrome mod 1337.
*
* Example:
* Input: 2
* Output: 987
* Explanation: 99 x 91 = 9009, 9009 % 1337 = 987
*
* Note:
* The range of n is [1,8].
*               
**********************************************************************************/

// 思路 1
// 暴力搜所有 n 位数的乘积

class Solution {
public:
    int largestPalindrome(int n) {
        if(n==1) return 9;
        long min = pow(10,n-1);
        long max = pow(10,n)-1;
        long i = max, sum = max + max, j = sum - i;
        while(1){
            j = sum - i;
            long res = i*j;
            if (Judge(res)) return res%1337;
            if(i-1 <= j)
            {
                i = max;
                sum--;
            }
            else i--;
        }
    }
    
    bool Judge(long m)
    {
        long s = 0;
        long t = m;
        while(t)
        {
            s = s*10 + t%10;
            t/=10;
        }
        return s==m;
    }
};

// Runtime: 1303 ms
// Memory Usage: N/A

/**********************************************************************************/

// 思路 2
// 暴力搜所有回文数

class Solution {
public:
    int largestPalindrome(int n) {
        if(n==1) return 9;
        int max = pow(10,n)-1;
        for(int i = max; i > max/10; i--){
            long num = Palindrome(i);
            for(int j = max; j >= num/j; j--){
                //cout << num << ' ' << j <<endl;
                if(num%j==0) return num%1337;
            }
        }
    }
    
    long Palindrome(int m)
    {
        int s = 0;
        int t = m;
        int c = 1;
        while(t)
        {
            s = s*10 + t%10;
            t/=10;
            c*=10;
        }
        return (long)m*(long)c+(long)s;
    }
};

// Runtime: 726 ms
// Memory Usage: N/A

/**********************************************************************************/

// 思路 3
// 数学知识
// 设 ret = a*10^n + b
// x = 10^n - a
// ret = (10^n - c)*(10^n - d)
// 那么 10^n*(10^n - x) = (10^n - c)*(10^n - d)
// 推出 10^n*(c + d - x) = c*d - b
// 因此只能 c+d = x   c*d = b 
// (c - d)^2 = x*x - 4*b
// 设 tmp = x*x - 4*b
// 所以 c - d = sqrt(tmp)
// 2*c = x+sqrt(tmp)
// 也就是 tmp 为平方数，x + sqrt(tmp) 为偶数
// 以此为条件筛选

class Solution {
public:
    int largestPalindrome(int n) {
        if (n==1)
            return 9;
        for (long i = 2; i <= pow(10, n)-1; i++){
            long a = pow(10, n) - i;
            long b = Reverse(a);
            long tmp = i*i - 4*b;
            if (tmp >= 0){
                long s = (long)sqrt(tmp);
                if(s*s == tmp && (i + s)%2 == 0)
                {
                    long long ret = pow(10, n)*(long long)a;
                    ret = ret + b;
                    return ret % 1337;
                }
            }
        }
        return 0;
            
        
    }
    
    long Reverse(int m)
    {
        int s = 0;
        int t = m;
        int c = 1;
        while(t)
        {
            s = s*10 + t%10;
            t/=10;
        }
        return s;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Largest Palindrome Product.
// Memory Usage: 6 MB, less than 95.00% of C++ online submissions for Largest Palindrome Product.