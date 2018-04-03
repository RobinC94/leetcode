// Source : https://oj.leetcode.com/problems/merge-sorted-array/
// Author : Robin Chen
// Date   : 2017.7.12

/********************************************************************************** 
* 
* Given two sorted integer arrays A and B, merge B into A as one sorted array.
* 
* Note:
*   You may assume that A has enough space (size that is greater or equal to m + n) 
*   to hold additional elements from B. The number of elements initialized in A and B 
*   are m and n respectively.
*               
**********************************************************************************/

// 这题第一次让我意识到STL里面的东西不是万能的
// 要按需选取
// 思路1：直接插入

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (m == 0){
            nums1 = nums2;
            return;
        }
        vector<int> nums;

        for(int i = 0; i < m; i++){
            nums.push_back(nums1[i]);
        }
        nums1 = nums;
        int pos = 0;
        for(int i = 0; i < n; ++i){
            while(nums1[pos] < nums2[i] && pos < nums1.size())
                pos++;
            nums1.insert(nums1.begin() + pos, nums2[i]);
        }
    }
};

// Status: Accepted
// Runtime: 3 ms
// 100.00%
// vector的优点是下标，不适合在中间插入删除

/**********************************************************************************/

// 思路2：构造一个新数组
// 实现起来很方便，缺点在于要进行一次复制

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector <int> nums(m + n);
    int i = 0, j = 0, k = 0;
    while(j < m || k < n){
        if (j >= m){
            nums[i++] = nums2[k++];
        }
        else if (k >= n)
            nums[i++] = nums1[j++];
        else
            nums[i++] = nums1[j] < nums2[k] ? nums1[j++] : nums2[k++];
    }
    nums1 = nums;
    }
};

// Status: Accepted
// Runtime: 6 ms
// 99.88%

/**********************************************************************************/

// 思路3：标准答案
// 直接在nums1里面改
// 然而不需要插入，和那道字符串替换的题一样
// 从后往前

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        m -= 1;
        n -= 1;
        int i = m + n + 1;
        while(m >= 0 || n >= 0){
            if (m < 0)
                nums1[i--] = nums2[n--];
            else if (n < 0)
                nums1[i--] = nums1[m--];
            else
                nums1[i--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
        }
    }
};

// Status: Accepted
// Runtime: 3 ms
// 100.00%