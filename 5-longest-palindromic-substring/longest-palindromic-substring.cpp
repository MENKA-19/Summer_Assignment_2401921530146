class Solution {
public:
    
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int start = 0, maxLen = 0;

        for (int i = 0; i < s.length(); i++) {
            // Case 1: Odd length palindromes (e.g., "aba")
            int left1 = i, right1 = i;
            while (left1 >= 0 && right1 < s.length() && s[left1] == s[right1]) {
                left1--;
                right1++;
            }
            int len1 = right1 - left1 - 1;

            // Case 2: Even length palindromes (e.g., "abba")
            int left2 = i, right2 = i + 1;
            while (left2 >= 0 && right2 < s.length() && s[left2] == s[right2]) {
                left2--;
                right2++;
            }
            int len2 = right2 - left2 - 1;

            // Update maximum tracking bounds
            int len = max(len1, len2);
            if (len > maxLen) {
                maxLen = len;
                start = i - (len - 1) / 2;
            }
        }
        return s.substr(start, maxLen);
    

    }
};