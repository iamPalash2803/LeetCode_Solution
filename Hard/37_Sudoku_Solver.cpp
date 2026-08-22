/*
 * Problem #37: Sudoku Solver
 * Difficulty: Hard
 *
 * ----- Description -----
 *
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 * 
 * A sudoku solution must satisfy all of the following rules:
 * 
 * 
 * 	Each of the digits 1-9 must occur exactly once in each row.
 * 	Each of the digits 1-9 must occur exactly once in each column.
 * 	Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
 * 
 * 
 * The '.' character indicates empty cells.
 * 
 *  
 * Example 1:
 * 
 * Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
 * Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
 * Explanation: The input board is shown above and the only valid solution is shown below:
 * 
 * 
 * 
 * 
 *  
 * Constraints:
 * 
 * 
 * 	board.length == 9
 * 	board[i].length == 9
 * 	board[i][j] is a digit or '.'.
 * 	It is guaranteed that the input board has only one solution.
 *
 * ----- Solution -----
 */

class Solution {
public:
    bool isSafe(vector<vector<char>> &board, int row, int col, char digit)
    {

        // horizontal cheak
        for (int j = 0; j < 9; j++)
        {
            if (board[row][j] == digit)
            {
                return false;
            }
        }

        // vertical cheak
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] == digit)
            {
                return false;
            }
        }

        //Individual 9*9 grid cheak
        int sRow = (row / 3) * 3;
        int sCol = (col / 3) * 3;

        for (int i = sRow; i <= sRow + 2; i++)
        {
            for (int j = sCol; j <= sCol + 2; j++)
            {
                if (board[i][j] == digit)
                {
                    return false;
                }
            }
        }

        return true;
    }

    bool helper(vector<vector<char>> &board, int row, int col)
    {

        if (row == 9)
        {
            return true;
        }

        int nextRow = row, nextCol = col + 1;
        if (nextCol == 9)
        {
            nextRow = row + 1;
            nextCol = 0;
        }

        // If the current cell already contains a number,
        // don't change it. Simply move to the next cell.
        if (board[row][col] != '.')
        {
            return helper(board, nextRow, nextCol);
        }

        // place correct Digit
        for (char digit = '1'; digit <= '9'; digit++)
        {
            if (isSafe(board, row, col, digit))
            {
                board[row][col] = digit;
                // Try solving the remaining board.
                if (helper(board, nextRow, nextCol))
                {
                    return true;   // Solution found
                }

                // Choice was wrong → undo it
                // and try the next digit.
                board[row][col] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        helper(board,0, 0);
    }
};