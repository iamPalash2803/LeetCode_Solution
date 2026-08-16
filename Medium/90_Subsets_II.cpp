/*
 * Problem #90: Subsets II
 * Difficulty: Medium
 *
 * ----- Description -----
 *
 * Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
 * 
 * The solution set must not contain duplicate subsets. Return the solution in any order.
 * 
 *  
 * Example 1:
 * Input: nums = [1,2,2]
 * Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
 * Example 2:
 * Input: nums = [0]
 * Output: [[],[0]]
 * 
 *  
 * Constraints:
 * 
 * 
 * 	1 <= nums.length <= 10
 * 	-10 <= nums[i] <= 10
 *
 * ----- Solution -----
 */

class Solution {
public:

    void getAllSubsets(vector<int> &nums, vector<int> &ans, int i, vector<vector<int>> &allSubsets)
    {

        if (i == nums.size())
        {
            // store subsets
            allSubsets.push_back(ans);
            return;
        }

        // include
        ans.push_back(nums[i]);
        getAllSubsets(nums, ans, i + 1, allSubsets);

        ans.pop_back(); // backtrack

        // Skipping the duplicate values
        int idx = i + 1;
        while (idx < nums.size() && nums[idx] == nums[idx - 1])
        {
            idx++;
        }

        // exclude
        getAllSubsets(nums, ans, idx, allSubsets);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // Sort only once.
        // Duplicate elements become adjacent.
        sort(nums.begin(), nums.end());
        vector<vector<int>> allSubsets;

        vector<int> ans;

        getAllSubsets(nums, ans, 0, allSubsets);

        return allSubsets;
    }
};