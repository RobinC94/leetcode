// Source : https://leetcode.com/problems/house-robber/
// Author : Robin Chen
// Date   : 2020.6.1

/********************************************************************************** 
* 
* You are a professional robber planning to rob houses along a street. 
* Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
* Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*
* Example 1:
*
* Input: [1,2,3,1]
* Output: 4
* Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
*              Total amount you can rob = 1 + 3 = 4.
*
* Example 2:
* Input: [2,7,9,3,1]
* Output: 12
* Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
*              Total amount you can rob = 2 + 9 + 1 = 12.
*               
**********************************************************************************/

// DP 信手拈来

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 0){
            return 0;
        }
        if (len < 2){
            return nums[0];
        }
        vector<int> rec(len);
        rec[0] = nums[0];
        rec[1] = max(nums[0], nums[1]);
        for(int i = 2; i < len; ++i){
            rec[i] = max(rec[i-2]+nums[i], rec[i-1]);
        }
        return rec[len-1];
    }
};

// Success
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for House Robber.
// Memory Usage: 8 MB, less than 100.00% of C++ online submissions for House Robber.