// https://leetcode.com/problems/longest-valid-parentheses/
// Author : Robin Chen
// Date   : 2020.05.07

/********************************************************************************** 
* 
* Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

* Example 1: 
* Input: "(()"
* Output: 2
* Explanation: The longest valid parentheses substring is "()"
*
* Example 2:
* Input: ")()())"
* Output: 4
* Explanation: The longest valid parentheses substring is "()()"
*               
**********************************************************************************/

// 思路
// 开始想的是用上升-下降方法，每遇到左括号就+1，右括号就-1，用一个数组记录每个值最早出现的位置，这样每检查一个新的括号就去前面找长度
// 但是忽视了右括号不能比左括号先出现
// 于是还是采用栈去存括号
// 每遇到一个右括号就出栈一个左括号，得到当前合理长度并记录
// 然后再到前一位去找前面的合理长度是多少，把连续的合理长度加起来
// 开始是遍历记录一遍，再遍历查找一遍，后来发现其实每次记录之后就查找一次会更快

class Solution {
public:
    int longestValidParentheses(string s) {
        stack <int> left;
        int res = 0;
        int len = s.size();
        if (len < 2)
            return res;
        vector <int> record(len);
        for (int i = 0; i < len; ++i){
            if(s[i] == '('){
                left.push(i);
            }
            else {
                if (!left.empty()){
                    record[i] = i - left.top() + 1;
                    left.pop();
                    int pos = i;
                    int curLen = 0;
                    while(pos >= 0 && record[pos] > 0){
                        curLen += record[pos];
                        pos -= record[pos];
                    }
                    if (curLen > res)
                        res = curLen;
                }
            }
        }
        return res;
    }
};

// Success
// Runtime: 4 ms, faster than 96.32% of C++ online submissions for Longest Valid Parentheses.
// Memory Usage: 7.8 MB, less than 100.00% of C++ online submissions for Longest Valid Parentheses.