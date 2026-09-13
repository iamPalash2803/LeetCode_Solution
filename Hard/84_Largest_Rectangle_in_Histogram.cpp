/*
 * Problem #84: Largest Rectangle in Histogram
 * Difficulty: Hard
 *
 * ----- Description -----
 *
 * Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
 * 
 *  
 * Example 1:
 * 
 * Input: heights = [2,1,5,6,2,3]
 * Output: 10
 * Explanation: The above is a histogram where width of each bar is 1.
 * The largest rectangle is shown in the red area, which has an area = 10 units.
 * 
 * 
 * Example 2:
 * 
 * Input: heights = [2,4]
 * Output: 4
 * 
 * 
 *  
 * Constraints:
 * 
 * 
 * 	1 <= heights.length <= 105
 * 	0 <= heights[i] <= 104
 *
 * ----- Solution -----
 */

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s;
        vector<int> right(n, 0); //right nearest smaller element index array
        vector<int> left(n, 0);  //left nearest smaller element index array

        //Creating right smaller element index array
        for(int i = n-1; i>= 0; i--){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }
            right[i] = s.empty()? n: s.top();

            s.push(i);
        }

        //do empty the stack before crating left array
        while(!s.empty()){
            s.pop();
        }

        //Creating left smaller element index array
        for(int i = 0 ; i < n; i++){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }
            left[i] = s.empty()? -1: s.top();

            s.push(i);
        }

        int ans = 0;
        for(int i = 0; i<n; i++){
            int width = right[i] - left[i] - 1;  //width = r - l - 1;
            int currWidth = heights[i] * width;
            ans = max(ans, currWidth);
        }

        return ans;
    }
};