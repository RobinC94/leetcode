
// Source : https://oj.leetcode.com/problems/longest-palindromic-substring/
// Author : Robin Chen
// Date   : 2018.3.26

/********************************************************************************** 
* 
* Given a string S, find the longest palindromic substring in S. 
* You may assume that the maximum length of S is 1000, 
* and there exists one unique longest palindromic substring.
*
* Example:
* Input: "babad"
* Output: "bab"
* Note: "aba" is also a valid answer
*               
**********************************************************************************/

// 暴力搜是不可行的
// 一个简单的思路是搜索以当前位为中心的最长回文串
// 但同时要考虑偶数位回文串的可能性
// 所以如果当前位的下一位与本位相同，要跳过
// 但是遇到了输入为"ccc"输出为"cc"的情况
// 所以必须跳过所有与本位相同的位

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if(len <=1) return s;
        
        string res;
        int maxLen = 0;
        for (int i = 0; i < len; ++i)
        {
            if (i > len - maxLen/2) break;
            int front , back , palLen;
            for(front = i; front < len; front++){
                if(s[front] != s[i]){
                    break;
                }
            }
            front--;
            for(back = i; front < len && back >= 0; front++, back--){
                if (s[front] != s[back])
                    break;
                palLen = front - back + 1;
            }
            back++;
            if (palLen > maxLen){
                maxLen = palLen;
                res = s.substr(back, palLen);
            }
        }
        
        return res;
        
    }
};

// Status: Accepted
// Runtime: 12 ms
// 82.43%