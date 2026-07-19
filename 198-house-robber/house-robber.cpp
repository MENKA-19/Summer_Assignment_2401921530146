class Solution {
public:

    int max_amt(int n, vector<int>& dp,vector<int>& nums){

        if(n==0){
            return nums[0];
        }
        if(n<=1){
            return max(nums[0],nums[1]);
        }
        if(dp[n] != -1){
            return dp[n];
        }

        return dp[n] = max(nums[n]+max_amt(n-2,dp,nums),max_amt(n-1,dp,nums));

    }
    int rob(vector<int>& nums) {

        int n = nums.size();
        vector<int>dp(n,-1);
        int money = max_amt(n-1,dp,nums);
        return money;
        
    }
};