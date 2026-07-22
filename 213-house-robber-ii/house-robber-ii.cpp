class Solution {
public:
    
    int max_amt(int n, const vector<int>& nums, int start, vector<int>& dp) {
        // Base cases using relative indices
        if (n < start) 
        return 0;
        if (n == start) 
        return nums[start];
        if(n == start+1)
        return max(nums[start],nums[start+1]);
        
        // Return memoized result if already calculated
        if (dp[n] != -1) return dp[n];
        
        // Choices: rob current house + skip one, OR skip current house
        return dp[n] = max(nums[n] + max_amt(n - 2, nums, start, dp), 
                           max_amt(n - 1, nums, start, dp));
    }

    int rob(vector<int>& nums) {
         int n = nums.size();
        
        // 1. Fix the 1-element edge case
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        // DP arrays to store subproblem results
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        
        // Scenario 1: Rob from house 0 to n-2 (exclude last house)
        int rob_first = max_amt(n - 2, nums, 0, dp1);
        
        // Scenario 2: Rob from house 1 to n-1 (exclude first house)
        int rob_second = max_amt(n - 1, nums, 1, dp2);
        
        return max(rob_first, rob_second);
      

    }
};