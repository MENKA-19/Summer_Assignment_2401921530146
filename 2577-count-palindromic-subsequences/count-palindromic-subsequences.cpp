class Solution {
public:
    int countPalindromes(string s) {
        const long long MOD = 1e9 + 7;
        int n = s.size();

        // suffix[i][a][b] = number of "ab" pairs
        // in s[i...n-1]
        vector<vector<vector<long long>>> suffix(
            n + 1, vector<vector<long long>>(10, vector<long long>(10, 0))
        );

        long long cnt[10] = {};

        // Build suffix pair counts
        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1];

            int x = s[i] - '0';

            for (int b = 0; b < 10; b++) {
                suffix[i][x][b] += cnt[b];
            }

            cnt[x]++;
        }

        long long left[10][10] = {};
        long long single[10] = {};

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int x = s[i] - '0';

            // Right side starts AFTER i
            for (int a = 0; a < 10; a++) {
                for (int b = 0; b < 10; b++) {
                    ans = (ans + left[a][b] * suffix[i + 1][b][a]) % MOD;
                }
            }

            // Add current digit to left side
            for (int a = 0; a < 10; a++) {
                left[a][x] += single[a];
            }

            single[x]++;
        }

        return ans;
    }
};