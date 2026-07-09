class Solution {
public:
    int Stairs(int n,vector<int>& DP){
        if(n <= 2)
          return n;
        if(DP[n] != -1)
           return DP[n];
        return DP[n] = Stairs(n-1,DP) + Stairs(n-2,DP);   
    }
    int climbStairs(int n) {

        vector<int> DP(n+1,-1);
        return Stairs(n,DP);
    }
};