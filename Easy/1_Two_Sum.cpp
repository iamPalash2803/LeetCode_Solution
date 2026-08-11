/*
 * Problem #1: Two Sum
 * Difficulty: Easy
 *
 * ----- Description -----
 *
 * You are given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 * 
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * 
 * You can return the answer in any order.
 * 
 *  
 * Example 1:
 * 
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 * Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 * 
 * 
 * Example 2:
 * 
 * Input: nums = [3,2,4], target = 6
 * Output: [1,2]
 * 
 * 
 * Example 3:
 * 
 * Input: nums = [3,3], target = 6
 * Output: [0,1]
 * 
 * 
 *  
 * Constraints:
 * 
 * 
 * 	2 <= nums.length <= 104
 * 	-109 <= nums[i] <= 109
 * 	-109 <= target <= 109
 * 	Only one valid answer exists.
 * 
 * 
 *  
 * Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
 *
 * ----- Solution -----
 */

class Solution {
public:
    //this is better approch
    //brute approch is use of 2 for loop
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> arr;

        // Store {value, original index}
        for(int i = 0; i < nums.size(); i++)
        {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end());

        int left = 0;
        int right = arr.size() - 1;

        while(left < right)
        {
            int sum = arr[left].first + arr[right].first;

            if(sum == target)
            {
                return {arr[left].second, arr[right].second};
            }
            else if(sum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return {};
    }
};