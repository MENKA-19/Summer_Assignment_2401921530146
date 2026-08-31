
class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int kIndex = find(nums.begin(), nums.end(), k) - nums.begin();
        unordered_map<int, int> counts;
        int ans = 0;
        
        // Traverse Left
        for (int i = kIndex, balance = 0; i >= 0; --i) {
            if (nums[i] > k) ++balance;
            else if (nums[i] < k) --balance;
            counts[balance]++;
        }
        
        // Traverse Right
        for (int i = kIndex, balance = 0; i < nums.size(); ++i) {
            if (nums[i] > k) ++balance;
            else if (nums[i] < k) --balance;
            
            // Add matching left balances that yield an overall balance of 0 or 1
            ans += counts[-balance] + counts[1 - balance];
        }
        
        return ans;
    }
};
