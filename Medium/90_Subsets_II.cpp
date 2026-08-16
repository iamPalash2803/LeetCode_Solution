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

    void getAllSubsets(vector<int>& nums, vector<int> ans, int idx, set<vector<int>> &subSets){

        if(idx == nums.size()){
            sort(ans.begin(), ans.end());
            subSets.insert(ans);
            return;
        }


        // Include current element
        ans.push_back(nums[idx]);
        getAllSubsets(nums, ans, idx+1, subSets);

        // Exclude current element
        ans.pop_back();
        getAllSubsets(nums, ans, idx+1, subSets);

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ans;
        set<vector<int>> subSets;

        getAllSubsets(nums, ans, 0, subSets);

        // Convert set into vector
        vector<vector<int>> allSubsets(subSets.begin(), subSets.end());
        
        return allSubsets;
    }
};