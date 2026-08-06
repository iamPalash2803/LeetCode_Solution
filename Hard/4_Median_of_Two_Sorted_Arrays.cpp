/*
 * Problem #4: Median of Two Sorted Arrays
 * Difficulty: Hard
 *
 * ----- Description -----
 *
 * Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
 * 
 * The overall run time complexity should be O(log (m+n)).
 * 
 *  
 * Example 1:
 * 
 * Input: nums1 = [1,3], nums2 = [2]
 * Output: 2.00000
 * Explanation: merged array = [1,2,3] and median is 2.
 * 
 * 
 * Example 2:
 * 
 * Input: nums1 = [1,2], nums2 = [3,4]
 * Output: 2.50000
 * Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 * 
 * 
 *  
 * Constraints:
 * 
 * 
 * 	nums1.length == m
 * 	nums2.length == n
 * 	0 <= m <= 1000
 * 	0 <= n <= 1000
 * 	1 <= m + n <= 2000
 * 	-106 <= nums1[i], nums2[i] <= 106
 *
 * ----- Solution -----
 */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int i=0,j=0;
        int m = nums1.size();
        int n = nums2.size();

        while(i<m && j<n){
            if(nums1[i] <= nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }
            else{
                ans.push_back(nums2[j]);
                j++;
            }
        }
        // Copy remaining elements of nums1
        while(i<m){
            ans.push_back(nums1[i]);
            i++;

        }
        // Copy remaining elements of nums2
        while(j < n)
        {
            ans.push_back(nums2[j]);
            j++;
        }

        int size = ans.size();

        // Odd number of elements
        if(size % 2 == 1){
            return ans[size/2];
        }
        // Even number of elements
        return (ans[size/2] + ans[size/2 - 1]) / 2.0;
    }
};