// Source : https://leetcode.com/problems/remove-duplicate-letters/
// Author : Robin Chen
// Date   : 2019.6.28

/********************************************************************************** 
* 
* Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.
*
* Example 1:
*
* Input: "bcabc"
* Output: "abc"
* Example 2:
*
* Input: "cbacdcbc"
* Output: "acdb"
* 
*               
**********************************************************************************/

// 借鉴了大神
// 思路：1 用俩个vector 标记字符在串中的出现的次数，以及这个字符是否访问过。
// 2 先遍历一遍字符串，统计字符出现的次数
// 3 第二遍遍历字符，每次访问一个字符都将字符出现的次数减一，如果字符被访问过，直接跳过。否则与结果字符串尾端比较。如果要插入的字符比尾端字符小，而且尾端字符在后面的字符串中还有。就弹出尾端字符，设标记未访问。否则就插入字符。

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> vec(256, 0);
        vector<bool> visited(256, 0);
        
        for(char c : s)
            vec[c]++;
        string res = "";
        for(char c : s){
            vec[c]--;
            if(visited[c]) 
                continue;
            while(vec[res.back()] && c < res.back()){  
                visited[res.back()] = false;
                res.pop_back();
            }
            res += c;
            visited[c] = true;
        }
        return res;
        
    }
};

// Status: Accepted
// Runtime: 0 ms
// 100%