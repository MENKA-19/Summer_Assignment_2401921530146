class Solution {
public:
 
    int removePalindromeSub(string s) {
        if (s.empty()) return 0;
        
        // Two-pointer check for palindrome
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            if (s[left] != s[right]) {
                return 2; // Not a palindrome, takes 2 steps
            }
            left++;
            right--;
        }
        
        return 1; // Is a palindrome, takes 1 step
    }

};