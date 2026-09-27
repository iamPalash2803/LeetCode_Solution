/*
 * Problem #1298: Reverse Substrings Between Each Pair of Parentheses
 * Difficulty: Medium
 *
 * ----- Description -----
 *
 * You are given a string s that consists of lower case English letters and brackets.
 * 
 * Reverse the strings in each pair of matching parentheses, starting from the innermost one.
 * 
 * Your result should not contain any brackets.
 * 
 *  
 * Example 1:
 * 
 * Input: s = "(abcd)"
 * Output: "dcba"
 * 
 * 
 * Example 2:
 * 
 * Input: s = "(u(love)i)"
 * Output: "iloveu"
 * Explanation: The substring "love" is reversed first, then the whole string is reversed.
 * 
 * 
 * Example 3:
 * 
 * Input: s = "(ed(et(oc))el)"
 * Output: "leetcode"
 * Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.
 * 
 * 
 *  
 * Constraints:
 * 
 * 
 * 	1 <= s.length <= 2000
 * 	s only contains lower case English characters and parentheses.
 * 	It is guaranteed that all parentheses are balanced.
 *
 * ----- Solution -----
 */

class Solution {
public:
    string reverseParentheses(string str) {

        stack<char> s;

        for(int i = 0; i < str.size(); i++){

            if(str[i] != ')'){
                s.push(str[i]);
            }
            else{
                // Pop characters until '(' is found
                string temp = "";

                while(!s.empty() && s.top() != '('){
                    temp += s.top();
                    s.pop();
                }

                // Remove '('
                s.pop();

                // Push reversed part back into stack
                for(int j = 0; j < temp.size(); j++){
                    s.push(temp[j]);
                }
            }
        }

        // Build final answer from stack
        string ans = "";

        while(!s.empty()){
            ans += s.top();
            s.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};