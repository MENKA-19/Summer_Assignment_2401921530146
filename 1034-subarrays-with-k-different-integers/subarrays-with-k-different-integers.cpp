class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
           int n = nums.size();
        
        // Frequencies maps for the two different left pointers
        vector<int> count1(n + 1, 0);
        vector<int> count2(n + 1, 0);
        
        int left1 = 0, left2 = 0;
        int distinct1 = 0, distinct2 = 0;
        int total_subarrays = 0;
        
        for (int right = 0; right < n; right++) {
            int num = nums[right];
            
            // Manage the window for 'left1' (handles at most k distinct elements)
            if (count1[num] == 0) distinct1++;
            count1[num]++;
            
            // Manage the window for 'left2' (handles at most k-1 distinct elements)
            if (count2[num] == 0) distinct2++;
            count2[num]++;
            
            // Shrink window 1 if it has more than k distinct elements
            while (distinct1 > k) {
                count1[nums[left1]]--;
                if (count1[nums[left1]] == 0) distinct1--;
                left1++;
            }
            
            // Shrink window 2 if it has more than k-1 distinct elements
            while (distinct2 > k - 1) {
                count2[nums[left2]]--;
                if (count2[nums[left2]] == 0) distinct2--;
                left2++;
            }
            
            // The difference between the two left boundaries tells us exactly 
            // how many valid prefixes form a subarray with EXACTLY k distinct elements
            total_subarrays += (left2 - left1);
        }
        
        return total_subarrays;

    }
};