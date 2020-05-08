// Source : https://leetcode.com/problems/3sum-closest/
// Author : Robin Chen
// Date   : 2018.4.1

/********************************************************************************** 
* 
* Given an array S of n integers, find three integers in S such that the sum is 
* closest to a given number, target. Return the sum of the three integers. 
* You may assume that each input would have exactly one solution.
* 
*     For example, given array S = {-1 2 1 -4}, and target = 1.
* 
*     The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*           
**********************************************************************************/

// 和上一题一个思路
// 区别是不需要考虑查重的情况了

class Solution {
public:        
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();        
        int res = nums[0]+nums[1]+nums[2];
        if(len == 3) return res;
        int error = abs(res - target);
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < len - 2; ++i)
        {
            int begin = i+1, end = len - 1;
            while(begin < end){
                int y = nums[begin] + nums[end];
                if(y == target - nums[i]) return target;
                if(abs(target-(y+nums[i])) < error){
                    error = abs(target-(y+nums[i]));
                    res = y+nums[i];
                }
                if(y > target - nums[i])                    
                    end--;
                else if(y < target - nums[i])
                    begin++;       
            }
            while(i < len-2 && nums[i] == nums[i+1]) ++i;
        }
        return res;
        
    }
};


// Status: Accepted
// Runtime: 10 ms
// 81.21%