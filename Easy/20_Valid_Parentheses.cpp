/*
 * Problem #20: Valid Parentheses
 * Difficulty: Easy
 *
 * ----- Description -----
 *
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * 	Open brackets must be closed by the same type of brackets.
 * 	Open brackets must be closed in the correct order.
 * 	Every close bracket has a corresponding open bracket of the same type.
 * 
 * 
 *  
 * Example 1:
 * 
 * 
 * Input: s = "()"
 * 
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "()[]{}"
 * 
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "(]"
 * 
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: s = "([])"
 * 
 * Output: true
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: s = "([)]"
 * 
 * Output: false
 * 
 * 
 *  
 * Constraints:
 * 
 * 
 * 	1 <= s.length <= 104
 * 	s consists of parentheses only '()[]{}'.
 *
 * ----- Solution -----
 */

class Solution {
public:
    bool isValid(string str) {
        stack<char> s;  

        for(int i = 0; i< str.size(); i++){
            if(str[i] == '(' || str[i] == '{' || str[i] == '['){
                s.push(str[i]);
            }
            else{//closing case

                if(s.size() == 0){
                    return false;
                }

                if((s.top() == '(' && str[i] == ')') || (s.top() == '{' && str[i] == '}') || (s.top() == '[' && str[i] == ']')){
                    s.pop();
                }

                else{// no match
                    return false;
                }
            }
        }
        return s.size() == 0;
    }
};