/*
 * Problem #18: 4Sum
 * Difficulty: Medium
 *
 * ----- Description -----
 *
 * Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
 * 
 * 
 * 	0 <= a, b, c, d < n
 * 	a, b, c, and d are distinct.
 * 	nums[a] + nums[b] + nums[c] + nums[d] == target
 * 
 * 
 * You may return the answer in any order.
 * 
 *  
 * Example 1:
 * 
 * Input: nums = [1,0,-1,0,-2,2], target = 0
 * Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 * 
 * 
 * Example 2:
 * 
 * Input: nums = [2,2,2,2,2], target = 8
 * Output: [[2,2,2,2]]
 * 
 * 
 *  
 * Constraints:
 * 
 * 
 * 	1 <= nums.length <= 200
 * 	-109 <= nums[i] <= 109
 * 	-109 <= target <= 109
 *
 * ----- Solution -----
 */

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {
            //Skip the first duplicate element if present
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n; j++)
            {
                // Skip duplicate second elements.
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int p = j + 1, q = n - 1;
                while (p < q)
                {
                    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[p] + (long long)nums[q];

                    if (sum < target)
                        p++;
                    else if (sum > target)
                        q--;
                    else
                    {
                        ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                        p++;
                        q--;
                        // Skip duplicate values of p
                        while (p < q && nums[p] == nums[p - 1])
                            p++;
                    }
                }
            }
        }
        return ans;
        
    }
};