// Source : https://oj.leetcode.com/problems/add-binary/
// Author : Robin Chen
// Date   : 2017.7.12

/********************************************************************************** 
* 
* Given two binary strings, return their sum (also a binary string).
* 
* For example,
* a = "11"
* b = "1"
* Return "100". 
*               
**********************************************************************************/

// 就看谁写的简洁

class Solution {
public:
    string addBinary(string a, string b) {
        int alen = a.length();
        int blen = b.length();
        int len = alen > blen ? alen : blen;
        string result(len,'0');
        int carry = 0;

        for(int i = 1; i <= len; i++){
            int sum = carry;
            if(alen - i >= 0) sum += a[alen-i] - '0';
            if(blen - i >= 0) sum += b[blen-i] - '0';
            carry = sum / 2;
            sum %= 2;
            result[len-i] += sum;
        }

        if (carry == 1)
            result = "1" + result;
        return result; 
    }
};

// Status: Accepted
// Runtime: 3 ms
// 100.00%
// wow！！！