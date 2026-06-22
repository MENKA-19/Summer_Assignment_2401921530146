class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i,j=-1,k;
        int n=nums.size();
        for(k=0;k<n;k++){
            if(nums[k]==0){
            j=k;
            break;
            }
        }
        if(j==-1)
        return;
        for(i=j+1;i<n;i++){
            if(nums[i]!=0){
                swap(nums[j],nums[i]);
                j++;
            }
        }
        
    }
};