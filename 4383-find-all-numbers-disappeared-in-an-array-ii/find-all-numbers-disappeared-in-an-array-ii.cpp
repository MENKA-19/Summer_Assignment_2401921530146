class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums,
                                               int lower,
                                               int upper) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        int prev = lower - 1;

        for (int x : nums) {

            // Ignore values outside [lower, upper]
            if (x < lower || x > upper)
                continue;

            // There is a missing range
            if (x - prev > 1) {
                ans.push_back({prev + 1, x - 1});
            }

            prev = x;
        }

        // Missing numbers after the last element
        if (prev < upper) {
            ans.push_back({prev + 1, upper});
        }

        return ans;
    }
};