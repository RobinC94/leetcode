// Source : https://oj.leetcode.com/problems/edit-distance/
// Author : Robin Chen
// Date   : 2018.09.14

/********************************************************************************** 
* 
* Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
*
* For example, given n = 3, a solution set is:
*
* [
*   "((()))",
*   "(()())",
*   "(())()",
*   "()(())",
*   "()()()"
* ]
*               
**********************************************************************************/

// 这道题卡了我很久
// 暴力破解试不可能的，实际上只要找到一种能够递归且不重复的遍历方式
// 针对当前字符串，保存左括号和右括号的数量
// 如果左括号的数量不超过最大数量，就可以添加左括号
// 如果右括号的数量小于左括号，那么就可以添加右括号
// 函数调用的结构就是在当前字符串下，如果长度够了就添加退出，不够的话就按上面的规则添加左右
// 刚好实现无重复无遗漏的遍历

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        int left = 0;
        int right = 0;
        string str = "";
        
        generateOne(str, left, right, n, res);
        return res;
    }
    
    void generateOne(string str, int left, int right, int num, vector<string> &res){
        if(str.length() == 2*num){
            res.push_back(str);
            return;
        }
        if(left < num){
            generateOne(str+'(', left+1, right, num, res);
        }
        if(right < left){
            generateOne(str+')', left, right+1, num, res);
        }
    }
    
};

// Status: Accepted
// Runtime: 0 ms
// 100%