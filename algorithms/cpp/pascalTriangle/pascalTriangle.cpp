// Source : https://oj.leetcode.com/problems/pascals-triangle/
// Author : Robi Chen
// Date   : 2017.11.22

/********************************************************************************** 
* 
* Given numRows, generate the first numRows of Pascal's triangle.
* 
* For example, given numRows = 5,
* Return
* 
* [
*      [1],
*     [1,1],
*    [1,2,1],
*   [1,3,3,1],
*  [1,4,6,4,1]
* ]
*               
**********************************************************************************/

// 体力题
// 既然规定用vector，那么就这样好了
// 实际上应该是list更合适

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> current;
		vector<vector<int>> result;
        if (numRows == 0) return result;
        
		current.push_back(1);
        result.push_back(current);
        if (numRows == 1) return result;

		current.push_back(1);
		result.push_back(current);
		if (numRows == 2) return result;

		for(int i = 3; i <= numRows; i++){
            vector<int> tmp;
            tmp.push_back(1);
            for(int j = 0; j < current.size() - 1; j++){
                tmp.push_back(current[j] + current[j+1]);
            }
            tmp.push_back(1);
            current = tmp;
            result.push_back(current);
		}
		return result;
    }
};

// Status: Accepted
// Runtime: 3 ms
// 96.61%
