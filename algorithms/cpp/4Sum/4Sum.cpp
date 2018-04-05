// Source : https://oj.leetcode.com/problems/4sum/
// Author : Robin Chen
// Date   : 2018.4.5

/********************************************************************************** 
* 
* Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? 
* Find all unique quadruplets in the array which gives the sum of target.
* 
* Note:
* 
* Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
* The solution set must not contain duplicate quadruplets.
* 
*     For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
* 
*     A solution set is:
*     (-1,  0, 0, 1)
*     (-2, -1, 1, 2)
*     (-2,  0, 0, 2)
* 
*               
**********************************************************************************/

// 首先按照之前排序的思路先掏出一个答案
// 3sum的时候还是O(n^2)，4sum就变成了O(n^3)
// 把去重和提前退出全部做好看看运行时间

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<vector<int>> res;
        if (len < 4) return res;
        vector<int> sing(4);
        sort(nums.begin(), nums.end());
     
        for(int i = 0; i < len-3; ++i){
            if(nums[i]*4 > target) break;
            for(int j = i+1; j < len-2; ++j){
                if(nums[i] + nums[j]*3 > target) break;
                int begin = j+1, end = len-1;
                int y = nums[i] + nums[j];
                while(begin < end){
                    int r = y+nums[begin]+nums[end];
                    if (r == target){
                        sing[0]=nums[i];
                        sing[1]=nums[j];
                        sing[2]=nums[begin];
                        sing[3]=nums[end];
                        res.push_back(sing);
             
                        while(begin < end && nums[begin] == nums[begin+1]) begin++;
                        while(begin < end && nums[end] == nums[end-1]) end--;
                        while(j < len-2 && nums[j] == nums[j+1]) ++j;
                        while(i < len-3 && nums[i] == nums[i+1]) ++i;
                        begin++;
                        end--;
                    }
                    else if(r > target) end--;
                    else if(r < target) begin++;
                }                
            }
        }
        return res;
    }
};

// Status: Accepted
// Runtime: 35 ms
// 57.56%
// 直方图告诉我们果然有更好的解

/**********************************************************************************/

// 然而看了一圈下来，全是N^3
// 可能他们是用C做的吧
