/*
 * Problem #131: Palindrome Partitioning
 * Difficulty: Medium
 *
 * ----- Description -----
 *
 * Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
 * 
 *  
 * Example 1:
 * Input: s = "aab"
 * Output: [["a","a","b"],["aa","b"]]
 * Example 2:
 * Input: s = "a"
 * Output: [["a"]]
 * 
 *  
 * Constraints:
 * 
 * 
 * 	1 <= s.length <= 16
 * 	s contains only lowercase English letters.
 *
 * ----- Solution -----
 */

class Solution {
public:
    bool isPalin(string s)
    {
        int st = 0, end = s.size() - 1;
        while (st <= end)
        {
            if (s[st] != s[end])
            {
                return false;
            }
            st++;
            end--;
        }
        return true;
    }

    void getAllParts(string s, vector<string> &partition, vector<vector<string>> &ans)
    {
        // Base case:
        // If the whole string has been partitioned,
        // store the current partition.
        if (s.size() == 0)
        {
            ans.push_back(partition);
            return;
        }

        // Try every possible prefix of the string.
        for (int i = 0; i < s.size(); i++)
        {
            string part = s.substr(0, i + 1);

            // Only continue if the chosen part is a palindrome.
            if (isPalin(part))
            {
                // Choose
                partition.push_back(part);
                // Recursively partition the remaining string.
                getAllParts(s.substr(i + 1), partition, ans);

                // BACKTRACK: Remove the current part before trying the next possible partition.
                partition.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> ans;
        vector<string> partition;

        getAllParts(s, partition, ans);

        return ans;
    }
};