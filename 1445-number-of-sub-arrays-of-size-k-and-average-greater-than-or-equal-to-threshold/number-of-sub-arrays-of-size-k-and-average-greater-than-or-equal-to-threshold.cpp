class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
       int st = 0,end = 0,sum = 0,c = 0;
       while(end < arr.size()){
         sum += arr[end];
         if(end-st+1 == k){
            if(sum/k >= threshold){
                c++;
            }
            sum = sum-arr[st];
            st++;
         }
         end++;
       }
       return c;
    }
};