// Source : https://oj.leetcode.com/problems/edit-distance/
// Author : Robin Chen
// Date   : 2016.11.10

/********************************************************************************** 
* 
* Given two words word1 and word2, find the minimum number of steps required to 
* convert word1 to word2. (each operation is counted as 1 step.)
* 
* You have the following 3 operations permitted on a word:
* 
* a) Insert a character
* b) Delete a character
* c) Replace a character
*               
**********************************************************************************/

// 人生第一道hard，也是第一次接触到DP
// 我甚至感觉以后遇到字符串比对有关的问题，直接DP就对了
// 思路：
// 非常巧妙的将字符串比对问题转化成了二位递归问题
// 实际上距离的变化就三种形式
// 和字符串1少了一位比
// 和字符串2烧了一位比
// 和两个都少一位比
// 取三者最小值，就对了
// 初始化的时候自然是[0][i]=i
// [j][0]=j

class Solution {
public:
    int minDistance(string word1, string word2) {
        int rows = word1.size() + 1;
        int cols = word2.size() + 1;
        int result[rows][cols];
        for(int i = 0; i < rows; ++i){
            result[i][0] = i;
        }
        for(int j = 0; j < cols; ++j)
            result[0][j] = j;
        for(int i = 1; i < rows; ++i) {
            char ci = word1[i-1];
            for(int j = 1; j < cols; ++j){
                char cj = word2[j-1];
                if (ci == cj) {
                    result[i][j] = result[i-1][j-1];
                } else {
                    int rep = result[i-1][j-1] + 1;
                    int ins = result[i][j-1] + 1;
                    int del = result[i-1][j] + 1;
                    int min = rep < ins ? rep : ins;
                    min = min < del ? min : del;
                    result[i][j] = min;
                }
            }
        }
        
        return result[rows-1][cols-1];
    }
};

// Status: Accepted
// Runtime: 9 ms
// 99.91%