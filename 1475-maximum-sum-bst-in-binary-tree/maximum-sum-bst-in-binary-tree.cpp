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
    int ans = 0;

    // Returns: {isBST, minimum, maximum, sum}
    vector<int> dfs(TreeNode* root) {
        if (root == NULL) {
            return {1, INT_MAX, INT_MIN, 0};
        }

        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);

        if (left[0] && right[0] &&
            root->val > left[2] &&
            root->val < right[1]) {

            int sum = root->val + left[3] + right[3];
            ans = max(ans, sum);

            int mn = min(root->val, left[1]);
            int mx = max(root->val, right[2]);

            return {1, mn, mx, sum};
        }

        return {0, 0, 0, 0};
    }

    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
