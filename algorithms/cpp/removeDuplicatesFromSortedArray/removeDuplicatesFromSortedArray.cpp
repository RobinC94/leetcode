// Source : https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array/
// Author : Robin Chen
// Date   : 2018.9.18

/********************************************************************************** 
* 
* Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
*
* Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
*
* Example 1:
*
* Given nums = [1,1,2],
*
* Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
*
* It doesn't matter what you leave beyond the returned length.
* Example 2:
*
* Given nums = [0,0,1,1,1,2,2,3,3,4],
*
* Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.
*
* It doesn't matter what values are set beyond the returned length.
* Clarification:
*
* Confused why the returned value is an integer but your answer is an array?
*
* Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.
*
* Internally you can think of this:
*
* // nums is passed in by reference. (i.e., without making a copy)
* int len = removeDuplicates(nums);
* 
* // any modification to nums in your function would be known by the caller.
* // using the length returned by your function, it prints the first len elements.
* for (int i = 0; i < len; i++) {
*     print(nums[i]);
* }
*               
**********************************************************************************/

// ？？？？

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        int id = 0;
        for(int i = 0; i < len; ++i){
            if(i == len - 1 || nums[i] != nums[i+1]){
                nums[id] = nums[i];
                id++;
            }
        }
        return id;
    }
};

// Status: Accepted
// Runtime: 36 ms
// 19.29%

// 莫非这帮变态找一个不重复id也要二分查找的？？？

// 下面这种方法虽然不是最快的，但是其非常符合c++11的风格，对迭代器的使用很是精髓，故收集下

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()==0) return 0;
        else if (nums.size()==1) {
            return 1;
        }
        auto pos_to_insert = nums.begin()+1; 
        int last_val = nums[0];
        for (auto it = nums.begin()+1; it!=nums.end(); it++){
            if ((*it)!=last_val) {
                last_val = *it;
                swap(*pos_to_insert, *it);
                pos_to_insert++;
                
            }
        }
        return pos_to_insert -  nums.begin();
    }
};

// Status: Accepted
// Runtime: 24 ms
// 43.64%