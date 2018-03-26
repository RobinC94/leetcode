// Source : https://oj.leetcode.com/problems/string-to-integer-atoi/
// Author : Robin Chen
// Date   : 2018.3.26

/********************************************************************************** 
* 
* Implement atoi to convert a string to an integer.
* 
* Hint: Carefully consider all possible input cases. If you want a challenge, 
*       please do not see below and ask yourself what are the possible input cases.
* 
* Notes: 
*   It is intended for this problem to be specified vaguely (ie, no given input specs). 
*   You are responsible to gather all the input requirements up front. 
* 
* 
* Requirements for atoi:
* 
* The function first discards as many whitespace characters as necessary until the first 
* non-whitespace character is found. Then, starting from this character, takes an optional 
* initial plus or minus sign followed by as many numerical digits as possible, and interprets 
* them as a numerical value.
* 
* The string can contain additional characters after those that form the integral number, 
* which are ignored and have no effect on the behavior of this function.
* 
* If the first sequence of non-whitespace characters in str is not a valid integral number, 
* or if no such sequence exists because either str is empty or it contains only whitespace 
* characters, no conversion is performed.
* 
* If no valid conversion could be performed, a zero value is returned. If the correct value 
* is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) 
* is returned.
*               
**********************************************************************************/

// 体力题，要考虑的情况非常之多
// 首先是去掉开头的空格
// 其次判断正负
// 一旦找到符号或正负那么即便空格也算非法字符
// 找到非法字符直接输出
// 对溢出的处理方式：最笨的是新建一个长整型

class Solution {
public:    
    int myAtoi(string str) {
        int res = 0;
        int len = str.length();
        int index = 0;
       
        bool neg = false;
        
        while(index < len){
            if (str[index] == ' ')
                index++;
            else if(str[index] == '+'){
                index++;
                break;
            }
            else if(str[index] == '-'){
                neg = true;
                index++;
                break;
            }
            else if(str[index] >= '0' && str[index] <= '9')
                break;
            else return res;
        }
        
        while(index < len){
            printf("%d\n", res);
            if(str[index] >= '0' && str[index] <= '9'){
                int bit = str[index] - '0';
                if(!neg){
                    long resJudge = (long)res*10+bit;
                    if (resJudge > INT_MAX)
                        return INT_MAX;
                    else res = res*10+bit;
                }
                else{
                    long resJudge = (long)res*10-bit;
                    if (resJudge < INT_MIN)
                        return INT_MIN;
                    else res = res*10-bit;
                }
                index++;
            }
            else return res;
        }      
        return res;       
    }
};

// 运行结果：
// Accepted	35ms	10.37%
// 我是真的菜

/**********************************************************************************/

// 于是学习了一下别人的简洁做法

class Solution {
public:    
    int myAtoi(string str) {
        int res = 0;
        int sign = 1;
        int index = 0;
        
        while(str[index] == ' ') index++;
        
        if (str[index] == '-' || str[index] == '+') 
            sign = 1 - 2 * (str[index++] == '-');
        
        while(str[index] <= '9' && str[index] >= '0'){
            if (res >  INT_MAX / 10 || (res == INT_MAX / 10 && str[index] - '0' > 7)) {
                if (sign == 1) return INT_MAX;
                else return INT_MIN;
            }
            res = res*10 + (str[index++] - '0');
        }     
        return res*sign;       
    }
};

// 运行结果：
// Accepted	27ms	60.64%
