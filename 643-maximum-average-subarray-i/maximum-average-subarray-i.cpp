class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int st = 0,end = 0,sum = 0;
        double avg,m = -DBL_MAX;
        while(end < nums.size()){
               sum += nums[end];
               if(end-st+1 == k){
                avg = double(sum)/double(k);
                m = max(m,avg);
                sum = sum-nums[st];
                  st++;
               }
               end++;
        }
        return m;
        
    }
};