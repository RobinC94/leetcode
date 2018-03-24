
// Source : https://oj.leetcode.com/problems/two-sum/
// Author : Robin Chen
// Date   : 2018.3.24

/********************************************************************************** 
*
* Given an array of integers, find two numbers such that they add up to a specific target number.
* 
* The function twoSum should return indices of the two numbers such that they add up to the target, 
* where index1 must be less than index2. Please note that your returned answers (both index1 and index2) 
* are not zero-based.
* 
* You may assume that each input would have exactly one solution.
* 
* Input: numbers={2, 7, 11, 15}, target=9
* Output: index1=1, index2=2      
*
**********************************************************************************/

// 思路1：两层循环搜索（注意vector用法）

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result(2);
        bool flag = false;
        for(int i = 0; i < nums.size()-1; i++)
        {
            if(flag) break;
            for (int j = i+1; j < nums.size(); j++)
            {
                if(nums[i] + nums[j] == target){
                	result[0] = i;
                	result[1] = j;
                	flag = true;
                	break;
                }
            }
       	}
       	return result;        
    }
};

// 运行结果：
// Accepted  124ms 37.24%
// 失败原因：复杂度为O(n^2)

/**********************************************************************************/

// 思路2：先排序，然后再搜索，排序复杂度为O(nlogn)，排序后搜索为O(n)
// 1. C++自带快速排序函数sort（虽然还是要会自己写）
// 2. 注意先将数组备份再排序
// 3. 搜索时分别从头尾开始，按照与target的大小关系前后移动（一定找得到！）
// 4. 最后为标准输出必须做一步判断大小和交换（这里又是教科书式的按位异或）

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result(2);
        vector<int> numsCopy;
        for(int i = 0; i < nums.size(); i++) numsCopy.push_back(nums[i]); 
        
        sort(numsCopy.begin(), numsCopy.end()); 
        vector<int> tmp(2);  
        int begin = 0, end = numsCopy.size() - 1;  
        while(begin < end){  
            int y = numsCopy[begin] + numsCopy[end];  
            if (y == target){  
                tmp[0]=numsCopy[begin];  
                tmp[1]=numsCopy[end];  
                break;  
            }else if(y > target) end--;  
            else begin++;  
        }  
  
        for(int i = 0; i < nums.size(); i++)  
            if(nums[i] == tmp[0]){  
                result[0]=i;  
                break;  
            }  
        for(int i = nums.size() - 1; i >= 0; i--)  
            if(nums[i] == tmp[1]){  
                result[1]=i;  
                break;  
            }  
  
        if (result[0] > result[1]){  
            result[0] = result[0]^result[1];  
            result[1] = result[0]^result[1];  
            result[0] = result[0]^result[1];  
        }  
  
        return result; 
        
    }
};

// 运行结果：
// Accepted  8ms 95.57%

/**********************************************************************************/

// 思路3：建立哈希查找表，复杂度为O(n)
// 1. 开始的思路是先遍历数组，建立一个哈希查找表，然后遍历数组的每个数去找与target的差是否出现
// 2. 改进版的思路是直接遍历数组，如果哈希表里没有与target的差就把该数加进查找表
// 3. C++自带map库
// *4. 无序查找最好使用unordered_map！！！！

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result(2);  
        unordered_map<int, int> finder;  
        for(int i = 0; i < nums.size(); i++){  
            if (finder.count(nums[i]) != 0){  
                result[0]=finder[nums[i]];  
                result[1]=i;  
                break;  
            }  
            finder[target - nums[i]] = i;  
        }  
        return result;  
    }
};

// 运行结果：
// Accepted  9ms 89.95%
// 竟然没有原来快？？？
