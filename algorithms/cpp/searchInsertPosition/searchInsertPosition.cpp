// https://leetcode.com/problems/search-insert-position/
// Author : Robin Chen
// Date   : 2020.05.08

/********************************************************************************** 
* 
* Given a sorted array and a target value, return the index if the target is found. 
* If not, return the index where it would be if it were inserted in order.
*
* You may assume no duplicates in the array.
*
* Example 1:
* Input: [1,3,5,6], 5
* Output: 2
*
* Example 2:
* Input: [1,3,5,6], 2
* Output: 1
*
* Example 3:
* Input: [1,3,5,6], 7
* Output: 4
*               
**********************************************************************************/

// 思路
// 标准二分
// 唯一注意的是搜索结束后需要判断一下大小，决定要不要后移一位

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int begin = 0, end = nums.size()-1;
        while(begin < end){
            int mid = (begin + end) / 2;
            if(nums[mid] > target)
                end = mid-1;
            else if(nums[mid] < target)
                begin = mid+1;
            else
                return mid;
        }
        if (nums[begin] < target)
            return begin+1;
        return begin;
    }
};

// Success
// Runtime: 12 ms, faster than 8.45% of C++ online submissions for Search Insert Position.
// Memory Usage: 10 MB, less than 7.81% of C++ online submissions for Search Insert Position.