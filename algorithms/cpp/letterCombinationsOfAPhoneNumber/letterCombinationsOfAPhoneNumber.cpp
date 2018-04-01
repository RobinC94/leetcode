// Source : https://oj.leetcode.com/problems/letter-combinations-of-a-phone-number/
// Author : Robin Chen
// Date   : 2018.4.1

/********************************************************************************** 
* 
* Given a digit string, return all possible letter combinations that the number could represent.
* 
* A mapping of digit to letters (just like on the telephone buttons) is given below.
* 
* Input:Digit string "23"
* Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
* 
* Note:
* Although the above answer is in lexicographical order, your answer could be in any order you want.
*               
**********************************************************************************/

// 体力题
// 注意res每次迭代要新建一个更新一次
// 一旦出现非法输入便直接输出结果
// 新函数 isdigit(char ch)判断输入是不是字符数字

class Solution {
public:
    string num2String(char i){
        switch(i){
            case '2': return "abc";
            case '3': return "def"; 
            case '4': return "ghi";
            case '5': return "jkl";
            case '6': return "mno";
            case '7': return "pqrs";
            case '8': return "tuv";
            case '9': return "wxyz";
            default: return "";
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        for(auto c:digits){
            if (c=='0' || c=='1') return res;
            string dict = num2String(c);
            if(res.empty())
                for(auto ch:dict){
                    string str;
                    str += ch;
                    res.push_back(str);
                }
            else{
                vector<string> r;
                for(auto &s:res){
                    for(auto ch:dict){
                        string tmp = s+ch;
                        r.push_back(tmp);
                    }
                        
                }
                res = r;
            }
        }       
        return res;     
    }
};

// Status: Accepted
// Runtime: 3 ms
// 79.31%