/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        vector<TreeNode*> st; // Vector acting as a stack to track ancestors
        int i = 0;
        int n = traversal.length();
        
        while (i < n) {
            // 1. Count the number of dashes to determine the depth of the current node
            int depth = 0;
            while (i < n && traversal[i] == '-') {
                depth++;
                i++;
            }
            
            // 2. Parse the integer value of the current node
            int value = 0;
            while (i < n && isdigit(traversal[i])) {
                value = value * 10 + (traversal[i] - '0');
                i++;
            }
            
            // 3. Create the new tree node
            TreeNode* node = new TreeNode(value);
            
            // 4. Backtrack the stack to find the parent node
            // The parent of a node at 'depth' must be at index 'depth - 1'
            while (st.size() > depth) {
                st.pop_back();
            }
            
            // 5. Connect the node to its parent
            if (!st.empty()) {
                if (!st.back()->left) {
                    st.back()->left = node; // Left child is filled first
                } else {
                    st.back()->right = node; // Right child is filled second
                }
            }
            
            // 6. Push current node onto the stack path
            st.push_back(node);
        }
        
        // The first node added to the stack is always the root of the tree
        return st[0];
    }
};