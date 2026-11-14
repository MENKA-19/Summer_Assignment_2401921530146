class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
         // 1. Sort width ascending; if widths are equal, sort height descending
        std::sort(envelopes.begin(), envelopes.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });

        // 2. Find Longest Increasing Subsequence (LIS) on heights using patience sorting
        std::vector<int> lis;
        for (const auto& env : envelopes) {
            int height = env[1];
            auto it = std::lower_bound(lis.begin(), lis.end(), height);
            
            if (it == lis.end()) {
                lis.push_back(height);
            } else {
                *it = height;
            }
        }

        return lis.size();
        
    }
};