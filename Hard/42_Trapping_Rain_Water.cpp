/*
 * Problem #42: Trapping Rain Water
 * Difficulty: Hard
 *
 * ----- Description -----
 *
 * Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
 * 
 *  
 * Example 1:
 * 
 * Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
 * 
 * 
 * Example 2:
 * 
 * Input: height = [4,2,0,3,2,5]
 * Output: 9
 * 
 * 
 *  
 * Constraints:
 * 
 * 
 * 	n == height.length
 * 	1 <= n <= 2 * 104
 * 	0 <= height[i] <= 105
 *
 * ----- Solution -----
 */

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        // leftMax[i] = maximum height from left to i
        vector<int> leftMax(n, 0);

        // rightMax[i] = maximum height from right to i
        vector<int> rightMax(n, 0);

        leftMax[0] = height[0];
        rightMax[n-1] = height[n-1];

        // Build left maximum array
        for(int i = 1; i < n; i++){
            leftMax[i] = max(height[i], leftMax[i-1]);
        }

        // Build right maximum array
        for(int i = n-2; i >= 0; i--){
            rightMax[i] = max(height[i], rightMax[i+1]);
        }

        int ans = 0;

        // Water at i = min(leftMax, rightMax) - height[i]
        for(int i = 0; i < n; i++){
            ans += min(leftMax[i], rightMax[i]) - height[i];
        }

        return ans;
    }
};