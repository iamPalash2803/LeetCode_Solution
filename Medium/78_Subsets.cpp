/*
 * Problem #78: Subsets
 * Difficulty: Medium
 *
 * ----- Description -----
 *
 * Given an integer array nums of unique elements, return all possible subsets (the power set).
 * 
 * The solution set must not contain duplicate subsets. Return the solution in any order.
 * 
 *  
 * Example 1:
 * 
 * Input: nums = [1,2,3]
 * Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 * 
 * 
 * Example 2:
 * 
 * Input: nums = [0]
 * Output: [[],[0]]
 * 
 * 
 *  
 * Constraints:
 * 
 * 
 * 	1 <= nums.length <= 10
 * 	-10 <= nums[i] <= 10
 * 	All the numbers of nums are unique.
 *
 * ----- Solution -----
 */

class Solution {
public:
    void getAllSubsets(vector<int>& nums, vector<int> ans, int idx, vector<vector<int>> &allSubsets){
        
        if(idx == nums.size()){
            allSubsets.push_back(ans);
            return;
        }

        ans.push_back(nums[idx]);
        getAllSubsets(nums, ans, idx+1, allSubsets);

        ans.pop_back();
        getAllSubsets(nums, ans, idx+1, allSubsets);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> allSubsets;

        getAllSubsets(nums, ans, 0, allSubsets);

        return allSubsets;
    }
};