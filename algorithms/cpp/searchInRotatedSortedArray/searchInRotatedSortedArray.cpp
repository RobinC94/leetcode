// https://leetcode.com/problems/search-in-rotated-sorted-array
// Author : Robin Chen
// Date   : 2020.05.08

/********************************************************************************** 
* 
* Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

* Example 1: 
* Input: "(()"
* Output: 2
* Explanation: The longest valid parentheses substring is "()"
*
* Example 2:
* Input: ")()())"
* Output: 4
* Explanation: The longest valid parentheses substring is "()()"
*               
**********************************************************************************/

// 思路
// 就是二分，把不同的情况理清楚，往左还是往右
// 事实证明，在每个循环先判断头尾比遇到具体情况再判断头尾要慢

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0)
            return -1;
        int start = 0, end = len-1;
        while(end >= start){
            if(nums[start] > target && nums[end] < target)
                return -1;
            int mid = (start + end) / 2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] > nums[end]){
                if(nums[start] <= target && nums[mid] > target)
                    end = mid-1;
                else
                    start = mid+1;
            }
            else if (nums[mid] < nums[start]){
                if(nums[mid] < target && nums[end] >= target)
                    start = mid+1;
                else
                    end = mid-1;
            }
            else if (nums[mid] < target)
                start = mid+1;
            else
                end = mid-1;
        }
        return -1;
    }
};

// Success
// Runtime: 4 ms, faster than 69.87% of C++ online submissions for Search in Rotated Sorted Array.
// Memory Usage: 11.3 MB, less than 6.03% of C++ online submissions for Search in Rotated Sorted Array.