// Source : https://oj.leetcode.com/problems/valid-parentheses/
// Author : Robin Chen
// Date   : 2018.4.5

/********************************************************************************** 
* 
* Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
* determine if the input string is valid.
* 
* The brackets must close in the correct order, "()" and "()[]{}" are all valid 
* but "(]" and "([)]" are not.
* 
*               
**********************************************************************************/

// 考的就是你记不记得栈的应用
// 需要注意 一个是第一个字符就是后半括号
// 另一个是最后栈非空

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.length(); ++i)
        {
            char ch = s[i];
            if(ch == '(' || ch == '[' || ch == '{'){
                st.push(ch);
            }
            else{
                if(st.empty()) return false;
                if(ch==')'){
                    if(st.top()!='(')
                        return false;
                    st.pop();
                }
                if(ch==']'){
                    if(st.top()!='[')
                        return false;
                    st.pop();
                }
                if(ch=='}'){
                    if(st.top()!='{')
                        return false;
                    st.pop();
                }
            }
        }
        if(st.empty())
            return true;
        else return false;
    }
};

// Status: Accepted
// Runtime: 4 ms
// 87.93%