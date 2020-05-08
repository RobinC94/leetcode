// https://leetcode.com/problems/next-permutation/
// Author : Robin Chen
// Date   : 2020.05.07

/********************************************************************************** 
* 
* Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
*
* If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
*
* The replacement must be in-place and use only constant extra memory.
*
* Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
* 
* 1,2,3 → 1,3,2
* 3,2,1 → 1,2,3
* 1,1,5 → 1,5,1
*               
**********************************************************************************/

// 思路
// 主要就是填坑
// 先一次反向搜索，找到第一个下降沿
// 然后反过来搜索，找到比下降后的数大的数当中最小的，交换两者的位置
// 后面用 STL 自带的排序，会很快

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1)
            return;
        int downPos = 0;
        for (int i = len-1; i > 0; --i){
            if (nums[i] > nums[i-1]){
                downPos = i;
                break;
            }
        }
        if (downPos > 0){
            int upPos = downPos;
            for(; upPos < len; ++upPos){
                if (nums[upPos] <= nums[downPos-1])
                    break;
            }
            int tmp = nums[upPos-1];
            nums[upPos-1] = nums[downPos-1];
            nums[downPos-1] = tmp;
        }
        sort(nums.begin()+downPos, nums.end());
        
    }
};

// Runtime: 4 ms, faster than 96.90% of C++ online submissions for Next Permutation.
// Memory Usage: 12.3 MB, less than 5.38% of C++ online submissions for Next Permutation.