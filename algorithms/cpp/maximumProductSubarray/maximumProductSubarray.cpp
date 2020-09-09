// Source : https://leetcode.com/problems/maximum-product-subarray/
// Author : Robin Chen
// Date   : 2020.09.08

/********************************************************************************** 
* 
* Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.
*
* Example 1:
* Input: [2,3,-2,4]
* Output: 6
* Explanation: [2,3] has the largest product 6.
*
* Example 2:
* Input: [-2,0,-1]
* Output: 0
* Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*     
**********************************************************************************/

// DP

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if ( n == 1 )
            return nums[0];
        int curMax[n];
        int curMin[n];
        curMax[0] = curMin[0] = nums[0];
        int res = nums[0];
        for (int i = 1; i < n; ++i){
            curMax[i] = max(nums[i], nums[i] * curMax[i-1]);
            curMax[i] = max(curMax[i], nums[i] * curMin[i-1]);
            curMin[i] = min(nums[i], nums[i] * curMax[i-1]);
            curMin[i] = min(curMin[i], nums[i] * curMin[i-1]);
            res = max(res, curMax[i]);
        }
        return res;
    }
};

// Runtime: 4 ms, faster than 98.58% of C++ online submissions for Maximum Product Subarray.
// Memory Usage: 12.1 MB, less than 14.25% of C++ online submissions for Maximum Product Subarray.