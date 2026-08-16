/*
 * Problem #287: Find the Duplicate Number
 * Difficulty: Medium
 *
 * ----- Description -----
 *
 * Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
 * 
 * There is only one repeated number in nums, return this repeated number.
 * 
 * You must solve the problem without modifying the array nums and using only constant extra space.
 * 
 *  
 * Example 1:
 * 
 * Input: nums = [1,3,4,2,2]
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * Input: nums = [3,1,3,4,2]
 * Output: 3
 * 
 * 
 * Example 3:
 * 
 * Input: nums = [3,3,3,3,3]
 * Output: 3
 * 
 *  
 * Constraints:
 * 
 * 
 * 	1 <= n <= 105
 * 	nums.length == n + 1
 * 	1 <= nums[i] <= n
 * 	All the integers in nums appear only once except for precisely one integer which appears two or more times.
 * 
 * 
 *  
 * Follow up:
 * 
 * 
 * 	How can we prove that at least one duplicate number must exist in nums?
 * 	Can you solve the problem in linear runtime complexity?
 *
 * ----- Solution -----
 */

class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        // Both pointers start from the first value.
        int slow = arr[0];
        int fast = arr[0]; 

        // Phase 1:
        // Find the meeting point inside the cycle.
        do
        {
            // Slow moves one step.
            slow = arr[slow];   //slow -> +1

            // Fast moves two steps.
            fast = arr[arr[fast]];   //fast-> +2

        } while (slow != fast);

        // Phase 2:
        // Reset slow to the beginning.
        slow = arr[0];

        // Move both pointers one step at a time.
        while (slow != fast)
        {
            slow = arr[slow];
            fast = arr[fast];
        }

        // Meeting point is the duplicate value.
        return slow;
    }
};