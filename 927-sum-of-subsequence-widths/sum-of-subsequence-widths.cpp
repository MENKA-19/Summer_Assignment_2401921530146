class Solution {
public:
   

int sumSubseqWidths(vector<int>& nums) {
    int n = nums.size();
    long long mod = 1e9 + 7; // Correct integer modulo representation (1000000007)
    
    // Step 1: Sort the array
    sort(nums.begin(), nums.end());
    
    long long total_sum = 0;
    long long p = 1; // Tracks powers of 2 on the fly (2^0, 2^1, 2^2, ...)

    // Step 2: Compute contributions in a single pass
    for (int i = 0; i < n; ++i) {
        // nums[i] is the maximum for 2^i subsequences
        // nums[n - 1 - i] is the minimum for those same 2^i subsequences
        long long max_contribution = (nums[i] * p) % mod;
        long long min_contribution = (nums[n - 1 - i] * p) % mod;
        
        // Add max contribution, subtract min contribution, and keep it positive
        total_sum = (total_sum + max_contribution - min_contribution + mod) % mod;
        
        // Update power of 2 for the next iteration
        p = (p * 2) % mod;
    }
    
    return total_sum;
}
};
