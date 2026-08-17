/*
 * Problem #51: N-Queens
 * Difficulty: Hard
 *
 * ----- Description -----
 *
 * The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
 * 
 * Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
 * 
 * Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
 * 
 *  
 * Example 1:
 * 
 * Input: n = 4
 * Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 * Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
 * 
 * 
 * Example 2:
 * 
 * Input: n = 1
 * Output: [["Q"]]
 * 
 * 
 *  
 * Constraints:
 * 
 * 
 * 	1 <= n <= 9
 *
 * ----- Solution -----
 */

class Solution {
public:

    bool isSafe(int row, int col, vector<string>& board, int n){
        // Check current row
        for(int j =0; j<n; j++){
            if(board[row][j] == 'Q')
                return false;
        }

        // Check current column
        for(int i = 0; i<n; i++){
            if(board[i][col] == 'Q')
                return false;
        }

        // Check upper-left diagonal
        for(int i = row, j =col; i >= 0 && j >= 0; i--, j--){
            if(board[i][j] == 'Q')
                return false;
        }

        // Check upper-right diagonal
        for(int i = row, j =col; i >= 0 && j < n; i--, j++){
            if(board[i][j] == 'Q')
                return false;
        }
        return true;
    }

    void nQueens(vector<string>& board, int row, int n, vector<vector<string>>& ans){
        // Base case:
        // All rows have been successfully filled.
        if(row == n){
            ans.push_back(board);
            return;
        }

        // Try placing a queen in every column
        // of the current row.
        for(int j =0; j<n; j++){
            // Only place a queen if the position is safe.
            if(isSafe(row, j, board, n)){
                board[row][j] ='Q';

                // Move to the next row only
                // after successfully placing the queen.
                nQueens(board, row+1, n, ans);

                // BACKTRACKING:
                // Remove the queen before trying
                // the next column.
                board[row][j] ='.';
            }
            
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n,'.'));
        vector<vector<string>> ans;

        nQueens(board, 0, n, ans);

        return ans;
    }
};