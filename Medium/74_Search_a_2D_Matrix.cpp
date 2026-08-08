/*
 * Problem #74: Search a 2D Matrix
 * Difficulty: Medium
 *
 * ----- Description -----
 *
 * You are given an m x n integer matrix matrix with the following two properties:
 * 
 * 
 * 	Each row is sorted in non-decreasing order.
 * 	The first integer of each row is greater than the last integer of the previous row.
 * 
 * 
 * Given an integer target, return true if target is in matrix or false otherwise.
 * 
 * You must write a solution in O(log(m * n)) time complexity.
 * 
 *  
 * Example 1:
 * 
 * Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
 * Output: false
 * 
 * 
 *  
 * Constraints:
 * 
 * 
 * 	m == matrix.length
 * 	n == matrix[i].length
 * 	1 <= m, n <= 100
 * 	-104 <= matrix[i][j], target <= 104
 *
 * ----- Solution -----
 */

class Solution {
public:

    bool searchInRow(vector<vector<int>>& matrix, int target, int row){
        int n = matrix[0].size(); // Number of columns
        int st = 0, end = n -1;

        while(st <= end){
            int mid = st + (end - st)/2;

            if(target == matrix[row][mid])
                return true;

            else if(target > matrix[row][mid])
                st = mid + 1;
            
            else
                end = mid - 1;
        }
        return false;
    }


    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //BS on total rows

        int m = matrix.size();      // Number of rows
        int n = matrix[0].size();   // Number of columns

        int stRow = 0, endRow = m-1;

        //This loop predict which is actual row where target may exists
        while(stRow <= endRow){
            int midRow = stRow + (endRow - stRow)/2;

            // Target present in thhis row -> apply BS on this Row
            if(target >= matrix[midRow][0] && target <= matrix[midRow][n-1])
                return searchInRow(matrix, target, midRow);
            
            else if( target < matrix[midRow][0])
                // target present at upper side's row
                endRow = midRow - 1;
            
            else
                // target present at down side's row
                stRow = midRow + 1;
        }
        return false;
    }
};