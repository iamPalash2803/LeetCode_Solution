/*
 * Problem #882: Peak Index in a Mountain Array
 * Difficulty: Medium
 *
 * ----- Description -----
 *
 * You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.
 * 
 * Return the index of the peak element.
 * 
 * Your task is to solve it in O(log(n)) time complexity.
 * 
 *  
 * Example 1:
 * 
 * 
 * Input: arr = [0,1,0]
 * 
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [0,2,1,0]
 * 
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: arr = [0,10,5,2]
 * 
 * Output: 1
 * 
 * 
 *  
 * Constraints:
 * 
 * 
 * 	3 <= arr.length <= 105
 * 	0 <= arr[i] <= 106
 * 	arr is guaranteed to be a mountain array.
 *
 * ----- Solution -----
 */

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int n = nums.size();
        int st = 1, end = n - 1;
        int mid;
        while (st <= end)
        {
            int mid = st + (end - st) / 2;
            if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1])
                return mid;

            else if (nums[mid] < nums[mid + 1]) 
                // lies in increasing slope
                st = mid + 1;
            else 
                // lies in decreasing slope
                end = mid - 1;
        }

        return mid;
    }
};