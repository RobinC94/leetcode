// Source : https://oj.leetcode.com/problems/palindrome-number/
// Author : Robin Chen
// Date   : 2018.3.26

/********************************************************************************** 
* 
* Determine whether an integer is a palindrome. Do this without extra space.
* 
* 
* Some hints:
* 
* Could negative integers be palindromes? (ie, -1)
* 
* If you are thinking of converting the integer to string, note the restriction of using extra space.
* 
* You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", 
* you know that the reversed integer might overflow. How would you handle such case?
* 
* There is a more generic way of solving this problem.
* 
*               
**********************************************************************************/

// 思路：
// 负数都不是
// 我的做法是提取最高位最低位比较，之后提取次高位次低位
// 为了实现提取功能需要保存当前高位低位的一个10的倍数
// 注意不能用在x中剔除最高最低位，不然遇到0就GG

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        
        int low = 1, high = 1;
        
        while (high <= x/10) high *=10;
        while(low < high){
            int tail = x%(10*low)/low;
            int head = x/high%10;
            if(head != tail) return false;
            high /= 10;
            low *= 10;
        }      
        
        return true;
    }
};

// Status: Accepted
// Runtime: 284 ms
// 9.52%
// 我嘞个擦

/**********************************************************************************/

// 标准答案的思路是掏出当前数的一半，将其反转，然后和另一半比较
// 如何知道已经掏出一半了呢？靠的是掏出的这一半乘以10大于剩下的原数除以10
// 然而弹幕大神指出这需要的空间复杂度不是o(1)而是o(n)
// 所以取最高最低位的思路不能变

// 改进方式是
// 1. 用log10求位数
// 2. 改x的同时要保留当前高位的位数

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x < 10)return true;
        
        int i = log10(x);
        
        while(i >= 0){
            int tail = x%10;
            int head = x/pow(10,i);
            if(head != tail) return false;
            x = x%(int)pow(10,i);
            x /= 10;
            i-=2;
        }      
        
        return true;
    }
};

// Status: Accepted
// Runtime: 345 ms
// 2.09%
// 你们这些人一定没按照题意！！！






