// Source : https://oj.leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// Author : Robin Chen
// Date   : 2017.7.12

/********************************************************************************** 
* 
* Given an array of integers that is already sorted in ascending order, 
* find two numbers such that they add up to a specific target number.
* 
* The function twoSum should return indices of the two numbers such that they add up to the target, 
* where index1 must be less than index2. Please note that your returned answers (both index1 and index2) 
* are not zero-based.
* 
* You may assume that each input would have exactly one solution.
* 
* Input: numbers={2, 7, 11, 15}, target=9
* Output: index1=1, index2=2 
* 
**********************************************************************************/

// 第一题的思路二

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;

        int begin = 0, end = numbers.size() - 1;
        while(begin < end){
            int y = numbers[begin] + numbers[end];
            if (y == target){
                result.push_back(begin + 1);
                result.push_back(end + 1);
                break;
            }else if(y > target) end--;
            else begin++;
        }

        return result;
    }
};

// Status: Accepted
// Runtime: 6 ms
// 99.79%
