
class Solution {
public:


    int partitions(vector<int>& nums, int k , int sum){

        int partition =1;
        long long par_sum =0;
        for(int i=0;i<nums.size();i++){

            if(par_sum +  nums[i] <= sum){
                par_sum+=nums[i];
                
            }
            else{

                partition+=1;
                par_sum = nums[i];
            }

        }
        return partition;        
    }
    int splitArray(vector<int>& nums, int k) {

        int st = *max_element(nums.begin(),nums.end());
        int end = accumulate(nums.begin(),nums.end(),0);

        while(st<=end){

            int mid = st + (end-st)/2;
            int no_of_par  = partitions(nums,k,mid);
            if(no_of_par > k){

                st = mid+1;
            }
            else{

                end = mid-1;
            }
            
        }

        return st;

            


        
    }
};