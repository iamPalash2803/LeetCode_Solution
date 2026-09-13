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
        int left = 0;
        int right = n - 1;
        int lMax = 0;
        int rMax = 0;
        int ans = 0;

        while(left < right) {
            // Keep track of maximum height from both sides.
            lMax = max(height[left], lMax);
            rMax = max(height[right], rMax);

            // Smaller maximum decides the trapped water.
            if(lMax < rMax) {
                ans += lMax - height[left];
                left++;
            }
            else {
                ans += rMax - height[right];
                right--;
            }
        }

        return ans;
    }
};