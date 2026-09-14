/*
 * Problem #387: First Unique Character in a String
 * Difficulty: Easy
 *
 * ----- Description -----
 *
 * Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
 * 
 *  
 * Example 1:
 * 
 * 
 * Input: s = "leetcode"
 * 
 * Output: 0
 * 
 * Explanation:
 * 
 * The character 'l' at index 0 is the first character that does not occur at any other index.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "loveleetcode"
 * 
 * Output: 2
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "aabb"
 * 
 * Output: -1
 * 
 * 
 *  
 * Constraints:
 * 
 * 
 * 	1 <= s.length <= 105
 * 	s consists of only lowercase English letters.
 *
 * ----- Solution -----
 */

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        queue<int> q;

        for(int i = 0; i < s.size(); i++){

            // Store index only when character appears for the first time.
            if(m.find(s[i]) == m.end()){
                q.push(i);
            }

            // Update frequency of current character.
            m[s[i]]++;

            // Remove indices whose characters are no longer unique.
            while(q.size() > 0 && m[s[q.front()]] > 1){
                q.pop();
            }
        }

        // Front of queue = index of first non-repeating character.
        return q.empty() ? -1 : q.front();
    }
};