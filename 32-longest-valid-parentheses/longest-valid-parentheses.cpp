class Solution {
public:
    int longestValidParentheses(string s) {
         std::stack<int> st;
        st.push(-1); // Base index for length calculation
        int max_len = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    // Current closing bracket becomes the new boundary base
                    st.push(i);
                } else {
                    // Valid length is current index minus the new top of stack
                    max_len = std::max(max_len, i - st.top());
                }
            }
        }
        return max_len;
    }
};