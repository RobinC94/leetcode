// Source : https://oj.leetcode.com/problems/sqrtx/
// Author : Robin Chen
// Date   : 2017.11.22

/********************************************************************************** 
* 
* Implement int sqrt(int x).
* 
* Compute and return the square root of x.
*               
**********************************************************************************/

// 太骚了，这题真的是太骚了
// 各路大神脑洞齐开演示如何优化一个这么简单的数学问题
// 我把所有的思路拿出来比对一下
// 思路1：直接搜索
// 用最直白的方式避免溢出

class Solution {
public:
    int mySqrt(int x) {
        int i;
        for (i = 1; i*i <= x && i < 46341; i++);
        return i-1;
    }
};

// Status: Accepted
// Runtime: 72 ms
// 3.81%
// 不用想也知道不行

/**********************************************************************************/

// 思路2：前期加速
// 先乘2，再加1

class Solution {
public:
    int mySqrt(int x) {
        int i;
        for (i = 1; i*i <= x && i < 46341; i*=2);
        i/=2;
        for (i = 1; i*i <= x && i < 46341; i++);
        return i-1;
    }
};

// Status: Accepted
// Runtime: 38 ms
// 13.32%
// 当数字大到一定境界的时候，还是慢

/**********************************************************************************/

// 思路3：二分查找
// 这下不用避免溢出了
// 事实上，我认为这是处理此类问题的标准做法
// log(N)是不会跟你讲道理的

class Solution {
public:
    int mySqrt(int x) {
        int left = 1, right = x, mid = left + (right - left) / 2;
        while (left <= right) {
            if (mid == x / mid) return mid;
            else {
                if (mid > x / mid) right = mid - 1;
                else left = mid + 1;
                mid = left + (right - left) / 2;
            }
        }
        return right;
    }
};

// Status: Accepted
// Runtime: 29 ms
// 25.50%

/**********************************************************************************/

// 思路4：牛顿法
// 数学的魅力就是这样
// 当你卡在瓶颈寻求突破，当你真正渴望力量的时候，数学才是最伟大的工具
// 我是真的没想到，刷编程题会用到数学知识
// 我很清楚也很熟悉牛顿法，直接让我做题我是想不到的
// 但我看到牛顿法这三个字的时候
// 醍醐灌顶茅塞顿开
// 服！
// 补充一：可微的情况下，梯度方法优于二分方法
// 补充二：

class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        int i = x - 1;
        while(i > x/i) i=(i + x/i)/2;  
        return i;
    }
};

// Status: Accepted
// Runtime: 12 ms
// 99.89%
// 舒服

/**********************************************************************************/

// 思路5：作弊
// 。。。。。。。。。。。。
// (╯‵□′)╯︵┻━┻

class Solution {
public:
    int mySqrt(int x) {
        return sqrt(x);
    }
};

// Status: Accepted
// Runtime: 15 ms
// 99.79%
// 永远不要以为你会比标准函数效率更高
