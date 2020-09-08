// Source : https://leetcode.com/problems/unique-paths-ii/
// Author : Robin Chen
// Date   : 2020.09.08

/********************************************************************************** 
* 
* A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
* The robot can only move either down or right at any point in time. 
* The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
* Now consider if some obstacles are added to the grids. How many unique paths would there be?
* An obstacle and empty space is marked as 1 and 0 respectively in the grid.
* 
* Note: m and n will be at most 100. 
*     
**********************************************************************************/

// DP

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int dp[m][n];
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else if (i == 0 && j == 0)
                    dp[i][j] = 1;
                else if (i == 0)
                    dp[i][j] = dp[i][j-1];
                else if (j == 0)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

// Runtime: 4 ms, faster than 96.86% of C++ online submissions for Unique Paths II.
// Memory Usage: 7.7 MB, less than 81.60% of C++ online submissions for Unique Paths II.