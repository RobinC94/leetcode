// Source : https://oj.leetcode.com/problems/roman-to-integer/
// Author : Robin Chen
// Date   : 2018.3.30

/********************************************************************************** 
* 
* Given a roman numeral, convert it to an integer.
* 
* Input is guaranteed to be within the range from 1 to 3999.
*               
**********************************************************************************/

// 体力题
// 按位切开，传给函数

class Solution {
public:
    int RomanToBit(string s, char ten, char five, char one){
        if (s.length() == 0) return 0;
        
        if (s[0] != five && s[0] != one) return 0;
        
        int res = 0, id = 0;
        while(s[id] == one){
            id++;
            res++;
            }
        if(s[id] == ten){
            return 10-res;
        }
        if(s[id] == five){
            id++;
            res = 5 - res;
        }
        while(s[id] == one){
            id++;
            res++;
        }
        return res;
    }
    
    int romanToInt(string s) {
        int res = 0;
        int id = 0;
        
        while(s[id] == 'M'){
            res += 1000;
            id++;
        }
        s = s.substr(id);
        id = 0;
        
        while(s[id] == 'M' || s[id] == 'D' || s[id] == 'C')
            id++;
        string tmp = s.substr(0,id);
        res += RomanToBit(tmp, 'M', 'D', 'C') * 100;
        s = s.substr(id);
        id = 0;
        
        while(s[id] == 'C' || s[id] == 'L' || s[id] == 'X')
            id++;
        tmp = s.substr(0,id);
        res += RomanToBit(tmp, 'C', 'L', 'X') * 10;
        s = s.substr(id);
        id = 0;
        
        while(s[id] == 'X' || s[id] == 'V' || s[id] == 'I')
            id++;
        tmp = s.substr(0,id);
        res += RomanToBit(tmp, 'X', 'V', 'I');
        
        return res;   
        
    }
};

// Status: Accepted
// Runtime: 124 ms
// 10.67%
// 其实我自己也知道这种做法不好

/**********************************************************************************/

// 别人是这么做的

class Solution {
public:
    int romanCharToInt(char ch){
        int d = 0;
        switch(ch){
        case 'I':  
            d = 1;  
            break;  
        case 'V':  
            d = 5;  
            break;  
        case 'X':  
            d = 10;  
            break;  
        case 'L':  
            d = 50;  
            break;  
        case 'C':  
            d = 100;  
            break;  
        case 'D':  
            d = 500;  
            break;  
        case 'M':  
            d = 1000;  
            break;  
        }
        return d;
    }
    int romanToInt(string s) {
        if (s.size()<=0) return 0;
        int result = romanCharToInt(s[0]);
        for (int i=1; i<s.size(); i++){
            int prev = romanCharToInt(s[i-1]);
            int curr = romanCharToInt(s[i]);
            //if left<right such as : IV(4), XL(40), IX(9) ...
            if (prev < curr) 
                result = result - prev + (curr-prev);
            else
                result += curr;
        }
        return result;
    }
};

// Status: Accepted
// Runtime: 116 ms
// 17.22%
// 行吧行吧