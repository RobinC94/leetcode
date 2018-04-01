// Source : https://oj.leetcode.com/problems/regular-expression-matching/
// Author : Robin Chen
// Date   : 2018.4.1

/********************************************************************************** 
* 
* Implement regular expression matching with support for '.' and '*'.
* 
* '.' Matches any single character.
* '*' Matches zero or more of the preceding element.
* 
* The matching should cover the entire input string (not partial).
* 
* The function prototype should be:
* bool isMatch(const char *s, const char *p)
* 
* Some examples:
* isMatch("aa","a") → false
* isMatch("aa","aa") → true
* isMatch("aaa","aa") → false
* isMatch("aa", "a*") → true
* isMatch("aa", ".*") → true
* isMatch("ab", ".*") → true
* isMatch("aab", "c*a*b") → true
* 
*               
**********************************************************************************/

// 首先仔细理解一下题意！
// 正则表达式匹配中！只有一个里面会出现.*这种东西，而且是第二个才会！
// 然后回归正题
// 先想明白这是一个递归的问题
// 第二点想明白方便对*的处理最好是从后往前
// 关键点就在于*的处理怎么递归了，暴力的做法是遍历一遍所有可能的长度
// 然而说起来暴力写起来其实很简单

class Solution {
public:
    static const int FRONT=-1;
    bool isMatch(string s, string p) {
        return myMatch(s,s.length()-1,p,p.length()-1);
    }
    bool myMatch(string s, int i, string p,int j)
    {
        if(j == FRONT)
            if(i == FRONT)    return true;
            else return false;
        if(p[j] == '*')
        {
            if(i > FRONT && (p[j-1] == '.' || p[j-1] == s[i]))
                if(myMatch(s,i-1,p,j))
                    return true;
            return myMatch(s,i,p,j-2);
        }
        if(p[j] == '.' || p[j] == s[i])
            return myMatch(s,i-1,p,j-1);
        return false;
    }
};

// Status: Accepted
// Runtime: 30 ms
// 37.91%

/**********************************************************************************/

// DP!!!DP!!!DP!!!
// 以后遇到字符串有关的问题直接DP
// 核心思路就两条：
// 

class Solution {
public:
    static const int FRONT=-1;
    bool isMatch(string s, string p) {
        int m = s.length(),n = p.length();
        bool dp[m+1][n+1];
        dp[0][0] = true;
//初始化第0行,除了[0][0]全为false，毋庸置疑，因为空串p只能匹配空串，其他都无能匹配
        for (int i = 1; i <= m; i++)
            dp[i][0] = false;
//初始化第0列，只有X*能匹配空串，如果有*，它的真值一定和p[0][j-2]的相同（略过它之前的符号）
        for (int j = 1; j <= n; j++)
            dp[0][j] = j > 1 && '*' == p[j - 1] && dp[0][j - 2];

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (p[j - 1] == '*')
                {
                    dp[i][j] = dp[i][j - 2] || (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j];

                }
                else   //只有当前字符完全匹配，才有资格传递dp[i-1][j-1] 真值
                {
                    dp[i][j] = (p[j - 1] == '.' || s[i - 1] == p[j - 1]) && dp[i - 1][j - 1];

                }
            }
        }
        return dp[m][n];
    }
};

// Status: Accepted
// Runtime: 18 ms
// 47.56%