/*
 * Problem #567: Permutation in String
 * Difficulty: Medium
 *
 * ----- Description -----
 *
 * Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
 * 
 * In other words, return true if one of s1's permutations is the substring of s2.
 * 
 *  
 * Example 1:
 * 
 * Input: s1 = "ab", s2 = "eidbaooo"
 * Output: true
 * Explanation: s2 contains one permutation of s1 ("ba").
 * 
 * 
 * Example 2:
 * 
 * Input: s1 = "ab", s2 = "eidboaoo"
 * Output: false
 * 
 * 
 *  
 * Constraints:
 * 
 * 
 * 	1 <= s1.length, s2.length <= 104
 * 	s1 and s2 consist of lowercase English letters.
 *
 * ----- Solution -----
 */

class Solution {
public:

    // Compare both frequency arrays.
    // If every character frequency matches,
    // the current window is a permutation of s1.
    bool isFreqSame(int freq[], int windFreq[])
    {
        for(int i = 0; i < 26; i++)
        {
            if(freq[i] != windFreq[i])
            {
                return false;
            }
        }

        return true;
    }

    bool checkInclusion(string s1, string s2) {
        
        // Edge Case:
        // A larger string cannot be a substring of a smaller string.
        if (s1.length() > s2.length()){
            return false;
        }


        int freq[26] = {0}; //as only small a to z available in string
        for(int i =0; i< s1.length(); i++){
            int idx = s1[i] - 'a';   // a -> 0, b->1
            freq[idx]++;
        }

        int windSize = s1.length();
        for(int i =0; i <= s2.length()-windSize; i++){
            int windIdx = 0, idx =i;
            int windFreq[26] = {0};

            // Build frequency array for current window.
            while(windIdx < windSize){
                windFreq[s2[idx] - 'a']++;
                windIdx++;
                idx++;
            }

            // Window matches s1 frequency.
            if(isFreqSame(freq, windFreq)){
                return true;
            }
        }
        return false;
    }
};