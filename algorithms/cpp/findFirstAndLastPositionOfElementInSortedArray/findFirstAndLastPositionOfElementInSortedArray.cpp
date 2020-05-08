// https://leetcode.com/problems/search-in-rotated-sorted-array
// Author : Robin Chen
// Date   : 2020.05.08

/********************************************************************************** 
* 
* Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
*
* Your algorithm's runtime complexity must be in the order of O(log n).
*
* If the target is not found in the array, return [-1, -1].
*
* Example 1:
* Input: nums = [5,7,7,8,8,10], target = 8
* Output: [3,4]

* Example 2:
* Input: nums = [5,7,7,8,8,10], target = 6
* Output: [-1,-1]
*               
**********************************************************************************/

// 思路
// 二分，先二分找到目标，再分别二分去找头和尾
// 有个小细节，在判断边界的时候可以利用++ -- 来规避整除 bug
// 但是不够快，也没有找到更快的例子

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
// Runtime: 16 ms, faster than 18.27% of C++ online submissions for Find First and Last Position of Element in Sorted Array.
// Memory Usage: 13.8 MB, less than 5.49% of C++ online submissions for Find First and Last Position of Element in Sorted Array.