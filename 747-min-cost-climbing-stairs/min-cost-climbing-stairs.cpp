class Solution {
public:
    int ways(int n,vector<int>& cost,vector<int>& DP){
        if(n <= 1)
          return 0;
        if(DP[n] != -1)
          return DP[n];
        return DP[n] = min(cost[n-1]+ways(n-1,cost,DP),cost[n-2]+ways(n-2,cost,DP));
    }
    int minCostClimbingStairs(vector<int>& cost) { 
          
         int n = cost.size();
         
         vector<int> DP(n+1,-1);
         return ways(n,cost,DP);

    }
};