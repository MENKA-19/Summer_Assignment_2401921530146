class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int i = 0,j = 1;
        int c = 1;
        while(j<nums.size()){
            if(nums[j] == nums[j-1])
              j++;
              else{
                  nums[i+1] = nums[j];
                   j++;
                   i++;
                   c++;
              }
        }
        return c;
        
    }

};