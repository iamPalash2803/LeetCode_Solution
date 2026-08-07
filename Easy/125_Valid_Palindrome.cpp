/*
 * Problem #125: Valid Palindrome
 * Difficulty: Easy
 *
 * ----- Description -----
 *
 * A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
 * 
 * Given a string s, return true if it is a palindrome, or false otherwise.
 * 
 *  
 * Example 1:
 * 
 * Input: s = "A man, a plan, a canal: Panama"
 * Output: true
 * Explanation: "amanaplanacanalpanama" is a palindrome.
 * 
 * 
 * Example 2:
 * 
 * Input: s = "race a car"
 * Output: false
 * Explanation: "raceacar" is not a palindrome.
 * 
 * 
 * Example 3:
 * 
 * Input: s = " "
 * Output: true
 * Explanation: s is an empty string "" after removing non-alphanumeric characters.
 * Since an empty string reads the same forward and backward, it is a palindrome.
 * 
 * 
 *  
 * Constraints:
 * 
 * 
 * 	1 <= s.length <= 2 * 105
 * 	s consists only of printable ASCII characters.
 *
 * ----- Solution -----
 */

class Solution {
public:
    bool isAlphaNumeric(char ch){
        if((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z')){
            return true;
        }
        return false;
    }

    bool isPalindrome(string s) {
        int st = 0, end = s.length()-1;

        while(st < end){
            if(!isAlphaNumeric(s[st])){
                st++;
                continue;
            }
            if(!isAlphaNumeric(s[end])){
                end--;
                continue;
            }
            if(tolower(s[st]) != tolower(s[end])){
                return false;
            }
            // Move both pointers after successful comparison
            st++;
            end--;
        }
        return true;
    }
};