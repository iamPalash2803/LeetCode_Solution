/*
 * Problem #34: Find First and Last Position of Element in Sorted Array
 * Difficulty: Medium
 *
 * ----- Description -----
 *
 * Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
 * 
 * If target is not found in the array, return [-1, -1].
 * 
 * You must write an algorithm with O(log n) runtime complexity.
 * 
 *  
 * Example 1:
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * Example 2:
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * Example 3:
 * Input: nums = [], target = 0
 * Output: [-1,-1]
 * 
 *  
 * Constraints:
 * 
 * 
 * 	0 <= nums.length <= 105
 * 	-109 <= nums[i] <= 109
 * 	nums is a non-decreasing array.
 * 	-109 <= target <= 109
 *
 * ----- Solution -----
 */

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> ans(2, -1);

        // Find first occurrence
        int st = 0;
        int end = nums.size() - 1;

        while (st <= end) {

            int mid = st + (end - st) / 2;

            if (nums[mid] == target) {
                ans[0] = mid;
                end = mid - 1;       // search towards left
            }
            else if (nums[mid] < target) {
                st = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        // Find last occurrence
        st = 0;
        end = nums.size() - 1;

        while (st <= end) {

            int mid = st + (end - st) / 2;

            if (nums[mid] == target) {
                ans[1] = mid;
                st = mid + 1;        // search towards right
            }
            else if (nums[mid] < target) {
                st = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return ans;
    }
};