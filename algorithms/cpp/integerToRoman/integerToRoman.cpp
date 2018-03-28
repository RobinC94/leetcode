// Source : https://oj.leetcode.com/problems/integer-to-roman/
// Author : Robin Chen
// Date   : 2018.3.28

/********************************************************************************** 
* 
* Given an integer, convert it to a roman numeral.
* 
* Input is guaranteed to be within the range from 1 to 3999.
*               
**********************************************************************************/

// 体力题，不多说

class Solution {
public:
    string BitToRoman(int n, char ten, char five, char one){
        string res;
        if(n == 9){
            res += one;
            res += ten;
        }
        else if (n >= 5){
            res += five;
            while(n > 5){
                n--;
                res +=one;
            }
        }
        else if (n==4){
            res += one;
            res += five;
        }
        else {
            while(n > 0){
                n--;
                res += one;
            }
        }
        return res;
    }
    string intToRoman(int num) {
        string s;
        int numBit = num/1000;
        while(numBit > 0){
            s += 'M';
            numBit--;
        }
        numBit = num%1000/100;
        s += BitToRoman(numBit,'M', 'D', 'C');
        numBit = num%100/10;
        s += BitToRoman(numBit,'C', 'L', 'X');
        numBit = num%10;
        s += BitToRoman(numBit,'X', 'V', 'I');
        
        return s;
    }
};

// Status: Accepted
// Runtime: 88 ms
// 35.13%