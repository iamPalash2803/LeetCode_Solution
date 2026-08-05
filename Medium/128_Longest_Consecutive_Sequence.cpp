/*
 * Problem #128: Longest Consecutive Sequence
 * Difficulty: Medium
 *
 * ----- Description -----
 *
 * Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
 * 
 * You must write an algorithm that runs in O(n) time.
 * 
 *  
 * Example 1:
 * 
 * Input: nums = [100,4,200,1,3,2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
 * 
 * 
 * Example 2:
 * 
 * Input: nums = [0,3,7,2,5,8,4,6,0,1]
 * Output: 9
 * 
 * 
 * Example 3:
 * 
 * Input: nums = [1,0,1,2]
 * Output: 3
 * 
 * 
 *  
 * Constraints:
 * 
 * 
 * 	0 <= nums.length <= 105
 * 	-109 <= nums[i] <= 109
 *
 * ----- Solution -----
 */

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }

        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0;

        for(int num : st){

            // (num - 1) does NOT exist
            // Start counting
            if(st.find(num-1) == st.end()){
                
                int current = num;
                int count = 1;

                // Keep checking whether
                // the next consecutive number exists.
                while(st.find(current+1) != st.end()){
                    count++;
                    current++;
                }
                longest = max(longest, count);

            }
        }
        return longest;
    }
};