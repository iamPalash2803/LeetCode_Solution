/*
 * Problem #239: Sliding Window Maximum
 * Difficulty: Hard
 *
 * ----- Description -----
 *
 * You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
 * 
 * Return the max sliding window.
 * 
 *  
 * Example 1:
 * 
 * Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
 * Output: [3,3,5,5,6,7]
 * Explanation: 
 * Window position                Max
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 *  1 [3  -1  -3] 5  3  6  7       3
 *  1  3 [-1  -3  5] 3  6  7       5
 *  1  3  -1 [-3  5  3] 6  7       5
 *  1  3  -1  -3 [5  3  6] 7       6
 *  1  3  -1  -3  5 [3  6  7]      7
 * 
 * 
 * Example 2:
 * 
 * Input: nums = [1], k = 1
 * Output: [1]
 * 
 * 
 *  
 * Constraints:
 * 
 * 
 * 	1 <= nums.length <= 105
 * 	-104 <= nums[i] <= 104
 * 	1 <= k <= nums.length
 *
 * ----- Solution -----
 */

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;

        //1st window
        for(int i = 0; i<k; i++){//O(k)
            while(dq.size() > 0 && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }

        //For reast of the windows
        for(int i=k; i<nums.size(); i++){//O(n-k)
            //ans of previous window
            res.push_back(nums[dq.front()]);

            //remove those are not the part of the current window
            while(dq.size() > 0 && dq.front() <= i-k){
                dq.pop_front();
            }

            //remove the smaller value from the end
            while(dq.size() > 0 && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }

            dq.push_back(i);
        }

        //For the maximum element of the last window
        res.push_back(nums[dq.front()]);

        return res;
    }
};