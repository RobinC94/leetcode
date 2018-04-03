// Source : https://oj.leetcode.com/problems/plus-one/
// Author : Robin Chen
// Date   : 2017.7.12

/********************************************************************************** 
* 
* Given a non-negative number represented as an array of digits, plus one to the number.
* 
* The digits are stored such that the most significant digit is at the head of the list.
*               
**********************************************************************************/

// 是个人都会做，就看谁的想法写起来方便简洁

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i=digits.size()-1; i>=0; i--){
            if (digits[i] != 9){
                digits[i] ++;
                break;
            }
            else{
                digits[i] = 0;
            }
        }
        
        if(digits[0] == 0){
            vector<int> result(digits.size()+1);
            result[0] = 1;
            for(int i=digits.size()-1; i!=0; i--){
                result[i+1] = digits[i];
            }
            return result;
            
        }else return digits;
       
    }
};

// Status: Accepted
// Runtime: 3 ms
// 99.81%