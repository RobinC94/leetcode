// Source : https://oj.leetcode.com/problems/longest-common-prefix/
// Author : Robin Chen
// Date   : 2018.4.1

/********************************************************************************** 
* 
* Write a function to find the longest common prefix string amongst an array of strings.
* 
*               
**********************************************************************************/

// 思路很简单
// 注意的是string虽然好用，但是功能不是无限多

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size()==0) return "";
        string s = strs[0];
        for(auto str:strs){
            int len = str.length();
            if(len == 0) return "";
            if(s.length()>len)
                s=s.erase(len);
            for (int i = 0; i<len ;++i){
                if(s[i] == '\0') break;
                if(str[i] != s[i]){
                    s = s.erase(i);
                    break;
                }
            }  
        }
        return s;
        
    }
};

// Status: Accepted
// Runtime: 9 ms
// 33.34%
