// Source : https://leetcode.com/problems/3sum/
// Author : Robin Chen
// Date   : 2018.4.1

/********************************************************************************** 
* 
* Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
* Find all unique triplets in the array which gives the sum of zero.
* 
* Note:
* 
* Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
* The solution set must not contain duplicate triplets.
* 
*     For example, given array S = {-1 0 1 2 -1 -4},
* 
*     A solution set is:
*     (-1, 0, 1)
*     (-1, -1, 2)
* 
*               
**********************************************************************************/

// 三个数的情况里面，排序的优势就显示出来了
// 反正也得搜两轮，时间复杂度为O(n^2)
// 实际上就是对第一个数循环搜索TwoSum
// 初次编程出错的几种情况：
// [0,0,0,0]会输出两个重复解


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int len = nums.size();
        if(len < 3) return res;
        vector<int> r(3);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len - 2; ++i){
            if(i > 0)
                if(nums[i] == nums[i-1])
                    continue;
            int begin = i+1, end = len - 1;
            while(begin < end){
                int y = nums[begin] + nums[end];
                if (y == -nums[i]){
                    if (res.size() != 0)
                        if(r[0] == nums[i] && r[1] == nums[begin]){
                            begin++;
                            end--;
                            continue;
                        }
                    r[0] = nums[i];
                    r[1] = nums[begin];
                    r[2] = nums[end]; 
                    res.push_back(r);
                    begin++;
                    end--;
                }
                else if(y > -nums[i]) 
                    end--;
                else if(y < -nums[i]) 
                    begin++;
            }
        }
        return res;      
    }
};

// Status: Accepted
// Runtime: 122 ms
// 50.25%

/**********************************************************************************/

// 可以做一些小优化
// 主要是人家敢用while

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int len = nums.size();
        if(len < 3) return res;
        vector<int> r(3);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len - 2; ++i){
            if(-nums[i] < 0) break;
            int begin = i+1, end = len - 1;
            while(begin < end){
                int y = nums[begin] + nums[end];
                if (y == -nums[i]){
                    r[0] = nums[i];
                    r[1] = nums[begin];
                    r[2] = nums[end]; 
                    res.push_back(r);
                    while(begin < end && nums[begin] == r[1]) begin++;
                    while(begin < end && nums[end] == r[2]) end--;
                }
                else if(y > -nums[i]) 
                    end--;
                else if(y < -nums[i]) 
                    begin++;
            }
            while(i+1 < len && nums[i+1] == nums[i]) i++;
        }
        return res;    
        
    }
};

// Status: Accepted
// Runtime: 115 ms
// 69.16%