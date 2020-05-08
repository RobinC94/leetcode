// https://leetcode.com/problems/valid-sudoku
// Author : Robin Chen
// Date   : 2020.05.08

/********************************************************************************** 
* 
* Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
* 
* Each row must contain the digits 1-9 without repetition.
* Each column must contain the digits 1-9 without repetition.
* Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.
* 
* The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
*               
**********************************************************************************/

// 思路
// 很简单，挨个判断就行，没有什么优化的空间
// 所以尝试用了 C 风格的程序并尽量压缩存储空间

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rec[27*9] = {};
        unsigned char h, w, n, s;
        for(unsigned char i = 0; i < 81; ++i){
            h = i / 9;
            w = i % 9;
            n = board[h][w] - '1';
            s = h / 3 * 3 + w / 3;
            if (n >= 0 && n <= 8){
                if(rec[h*9+n])
                    return false;
                rec[h*9+n] = true;
                if (rec[(w+9)*9+n])
                    return false;
                rec[(w+9)*9+n] = true;
                if (rec[(s+18)*9+n])
                    return false;
                rec[(s+18)*9+n] = true;
            }
        }
        return true;
    }
};

// Success
// Runtime: 32 ms, faster than 26.96% of C++ online submissions for Valid Sudoku.
// Memory Usage: 18.1 MB, less than 5.13% of C++ online submissions for Valid Sudoku.
// 然而还是不够