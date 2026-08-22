/*
 * Problem #39: Combination Sum
 * Difficulty: Medium
 *
 * ----- Description -----
 *
 * Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
 * 
 * The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
 * 
 * The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
 * 
 *  
 * Example 1:
 * 
 * Input: candidates = [2,3,6,7], target = 7
 * Output: [[2,2,3],[7]]
 * Explanation:
 * 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
 * 7 is a candidate, and 7 = 7.
 * These are the only two combinations.
 * 
 * 
 * Example 2:
 * 
 * Input: candidates = [2,3,5], target = 8
 * Output: [[2,2,2,2],[2,3,3],[3,5]]
 * 
 * 
 * Example 3:
 * 
 * Input: candidates = [2], target = 1
 * Output: []
 * 
 * 
 *  
 * Constraints:
 * 
 * 
 * 	1 <= candidates.length <= 30
 * 	2 <= candidates[i] <= 40
 * 	All elements of candidates are distinct.
 * 	1 <= target <= 40
 *
 * ----- Solution -----
 */

class Solution {
public:

    void helper(vector<int>& candidates, vector<vector<int>>& ans, vector<int> combin, int idx, int target, set<vector<int>>& s){

        if(idx == candidates.size() || target < 0){
            return;
        }

        // Insert only if this combination
        // has not already been generated.
        if(target == 0){
            if(s.find(combin) == s.end()){
                ans.push_back(combin);
                s.insert(combin);
            }
            return;
        }

        // TAKE current candidate
        combin.push_back(candidates[idx]);

        //include single time
        helper(candidates, ans, combin, idx+1, target-candidates[idx], s);

        // Same idx because we can reuse
        // the same candidate unlimited times.
        helper(candidates, ans, combin, idx, target-candidates[idx], s);

        //Backtrack
        combin.pop_back();
        
        helper(candidates, ans, combin, idx+1, target, s);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combin;
        set<vector<int>> s;

        helper(candidates, ans, combin, 0, target, s);

        return ans;
    }
};