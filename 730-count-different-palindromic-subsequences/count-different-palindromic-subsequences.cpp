class Solution {
public:
    
    int countPalindromicSubsequences(string s) {
        int n = s.length();
        long long MOD = 1e9 + 7;
        
        // dp[i][j] stores the number of distinct palindromic subsequences in s[i...j]
        vector<vector<long long>> dp(n, vector<long long>(n, 0));
        
        // Base cases: single character substrings
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }
        
        // Iterate over substring lengths from 2 up to n
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                
                if (s[i] != s[j]) {
                    dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
                } else {
                    int low = i + 1;
                    int high = j - 1;
                    
                    // Find the next occurrence of s[i] from the left
                    while (low <= high && s[low] != s[i]) {
                        low++;
                    }
                    // Find the previous occurrence of s[j] from the right
                    while (low <= high && s[high] != s[j]) {
                        high--;
                    }
                    
                    if (low > high) {
                        // Case 2a: No duplicate characters inside
                        dp[i][j] = dp[i + 1][j - 1] * 2 + 2;
                    } else if (low == high) {
                        // Case 2b: Exactly one duplicate character inside
                        dp[i][j] = dp[i + 1][j - 1] * 2 + 1;
                    } else {
                        // Case 2c: Two or more duplicate characters inside
                        dp[i][j] = dp[i + 1][j - 1] * 2 - dp[low + 1][high - 1];
                    }
                }
                
                // Keep the value positive and within modulo constraints
                dp[i][j] = (dp[i][j] + MOD) % MOD;
            }
        }
        
        return dp[0][n - 1];
    }


};