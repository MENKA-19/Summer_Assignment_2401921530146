class Solution {
public:

    vector<int> getMax(vector<int>& nums, int k) {
        vector<int> st;
        int drop = nums.size() - k;

        for (int x : nums) {
            while (!st.empty() && drop > 0 &&
                   st.back() < x) {
                st.pop_back();
                drop--;
            }
            st.push_back(x);
        }

        st.resize(k);
        return st;
    }

    bool greater(vector<int>& a, int i,
                 vector<int>& b, int j) {

        while (i < a.size() && j < b.size() &&
               a[i] == b[j]) {
            i++;
            j++;
        }

        return j == b.size() ||
               (i < a.size() && a[i] > b[j]);
    }

    vector<int> merge(vector<int>& a, vector<int>& b) {
        vector<int> res;
        int i = 0, j = 0;

        while (i < a.size() || j < b.size()) {
            if (greater(a, i, b, j))
                res.push_back(a[i++]);
            else
                res.push_back(b[j++]);
        }

        return res;
    }

    vector<int> maxNumber(vector<int>& nums1,
                          vector<int>& nums2, int k) {

        vector<int> ans;

        int m = nums1.size();
        int n = nums2.size();

        for (int i = max(0, k - n);
             i <= min(k, m); i++) {

            vector<int> a = getMax(nums1, i);
            vector<int> b = getMax(nums2, k - i);

            vector<int> candidate = merge(a, b);

            if (greater(candidate, 0, ans, 0))
                ans = candidate;
        }

        return ans;
    }
};
