// https://leetcode.com/problems/sudoku-solver/
// Author : Robin Chen
// Date   : 2020.05.22

/********************************************************************************** 
* 
* Write a program to solve a Sudoku puzzle by filling the empty cells.
*
* A sudoku solution must satisfy all of the following rules:
*
* Each of the digits 1-9 must occur exactly once in each row.
* Each of the digits 1-9 must occur exactly once in each column.
* Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
* Empty cells are indicated by the character '.'.
*               
* Note:
* The given board contain only digits 1-9 and the character '.'.
* You may assume that the given Sudoku puzzle will have a single unique solution.
* The given board size is always 9x9.
*
**********************************************************************************/

// 为了解这个问题，我专门开了一个项目研究数独，详情请见
// https://github.com/RobinC94/Sudoku.git
// 从中把解数独的部分解析出来，就是本答案

class Solution {
public:
    uint8_t board[81];
    bitset<9> record[81];
    int filled;
    bool valid;
    void solveSudoku(vector<vector<char>>& board) {
        init(board);
        solve();
        output(board);
    }
    
    bool fillValidBlank(){
        bool action = false;
        for (int i = 0; i < 9; ++i){
            for (uint8_t var = 0; var < 9; ++var){
                int posH = -1, posW = -1, posS = -1;
                for (int j = 0; j < 9; ++j){
                    auto curRec = record[i*9+j];
                    if(curRec.count() == 1 && curRec[var] == 1){
                        action = setValue(i, j, var+1);
                    }
                }
                for (int j = 0; j < 9; ++j){
                    auto curRecH = record[i*9+j];
                    if (curRecH[var] == 1){
                        if (posH == -1){
                            posH = j;
                        }
                        else{
                            posH = 10;
                        }
                    }
                }
                if (posH >=0 && posH < 9){ 
                    action = setValue(i, posH, var+1);
                }
                for (int j = 0; j < 9; ++j){
                    auto curRecW = record[j*9+i]; 
                    if (curRecW[var] == 1){
                        if (posW == -1){
                            posW = j;
                        }
                        else{
                            posW = 10;
                        }
                    }
                }
                if (posW >=0 && posW < 9){ 
                    action = setValue(posW, i, var+1);
                }
                for (int j = 0; j < 9; ++j){
                    auto curRecS = record[(i/3*3+j/3)*9+(i%3*3+j%3)];  
                    if (curRecS[var] == 1){
                        if (posS == -1){
                            posS = j;
                        }
                        else{
                            posS = 10;
                        }
                    }
                }
                if (posS >=0 && posS < 9){
                    action = setValue(i/3*3+posS/3, i%3*3+posS%3, var+1);
                }
                if (!valid){
                    return false;
                }
            }
        }
        return action;
    }
    
    void init(vector<vector<char> > inBoard){
        for (int i = 0; i < 81; ++i){
            board[i] = 0;
            record[i].set();
        }
        filled = 0;
        valid = true;
        for (int i = 0; i < 9; ++i){
            for (int j = 0; j < 9; ++j){
                if (inBoard[i][j] >= '1' && inBoard[i][j] <= '9'){
                    setValue(i, j, inBoard[i][j] - '1' + 1);
                }
            }
        }
    }
    
    void output(vector<vector<char> >& outBoard){
        for (int i = 0; i < 9; ++i){
            for (int j = 0; j < 9; ++j){
                outBoard[i][j] = '1'-1+board[i*9+j];
            }
        }
    }
    
    bool setValue(int h, int w, uint8_t var){
        if (record[h*9+w][var-1] == 0) {
            valid = false;
            return false;
        }
        board[h*9+w] = var;
        record[h*9+w].reset();
        for (int i = 0; i < 9; ++i){
            record[h*9+i][var-1] = 0;
            record[i*9+w][var-1] = 0;
            int j = i / 3;
            int k = i % 3;
            record[(h/3*3+j)*9+w/3*3+k][var-1] = 0;
        }
        filled++;
        return true;
    }
    
    bool solve(){
        while(fillValidBlank()){
            if (!valid){
                return false;
            }
        }
        if (filled == 81)
            return true;
        else{
            uint8_t oldBoard[81];
            std::bitset<9> oldRecord[81];
            int oldFilled = filled;
            int minChoice = 9;
            int minPos = -1;
            for (int i = 0; i < 81; ++i){
                oldBoard[i] = board[i];
                oldRecord[i] = record[i];
                if (record[i].count() > 0 && record[i].count() < minChoice){
                    minChoice = record[i].count();
                    minPos = i;
                }
            }
            if (minPos == -1){
                return false;
            }
            for (uint8_t var = 0; var < 9; var++){
                if(record[minPos][var] == 1){
                    setValue(minPos/9, minPos%9, var+1);
                    if (solve()){
                        return true;
                    }
                    else
                    {
                        for (int i = 0; i < 81; ++i){
                            board[i] = oldBoard[i];
                            record[i] = oldRecord[i];
                            filled = oldFilled;
                        }
                        record[minPos][var] = 0;
                        valid = true;
                        return solve();
                    }  
                }
            }
            return false;
        }
    }
};

// Success
// Runtime: 8 ms, faster than 84.41% of C++ online submissions for Sudoku Solver.
// Memory Usage: 6.4 MB, less than 100.00% of C++ online submissions for Sudoku Solver.