class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> freq(51, 0); // index 1 represents -1, 50 represents -50
        vector<int> ans;

        for (int i = 0; i < n; i++) {

            // Add current element
            if (nums[i] < 0) {
                freq[-nums[i]]++;
            }

            // Keep window size k
            if (i >= k) {
                if (nums[i - k] < 0) {
                    freq[-nums[i - k]]--;
                }
            }

            // Window is ready
            if (i >= k - 1) {
                int count = 0;
                int beauty = 0;

                // Smallest negative: -50 ... -1
                for (int val = 50; val >= 1; val--) {
                    count += freq[val];

                    if (count >= x) {
                        beauty = -val;
                        break;
                    }
                }

                ans.push_back(beauty);
            }
        }

        return ans;
    }
};