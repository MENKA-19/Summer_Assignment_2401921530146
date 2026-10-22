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
    vector<int> depth, ans;

    void dfs(TreeNode* root, int level) {
        if (!root) return;

        depth[root->val] = level;
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }

    void solve(TreeNode* root, int level, int maxDepth) {
        if (!root) return;

        ans[root->val] = maxDepth;

        solve(root->left, level + 1,
              max(maxDepth, level + (root->right ? 1 + depth[root->right->val] - level : 0)));

        solve(root->right, level + 1,
              max(maxDepth, level + (root->left ? 1 + depth[root->left->val] - level : 0)));
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        int n = 100001;
        depth.assign(n, 0);
        ans.assign(n, 0);

        dfs(root, 0);

        // Compute the answer for every node using depths of alternative branches.
        vector<int> order;
        function<void(TreeNode*)> collect = [&](TreeNode* node) {
            if (!node) return;
            order.push_back(node->val);
            collect(node->left);
            collect(node->right);
        };
        collect(root);

        // A direct per-node rerooting calculation using subtree heights.
        vector<int> subHeight(n, 0);
        function<int(TreeNode*)> height = [&](TreeNode* node) {
            if (!node) return -1;
            return subHeight[node->val] =
                1 + max(height(node->left), height(node->right));
        };
        height(root);

        function<void(TreeNode*, int, int)> reroot =
            [&](TreeNode* node, int level, int outside) {
                if (!node) return;

                ans[node->val] = outside;

                int leftHeight = node->left ? subHeight[node->left->val] : -1;
                int rightHeight = node->right ? subHeight[node->right->val] : -1;

                if (node->left) {
                    reroot(node->left, level + 1,
                           max(outside, level + 1 + rightHeight));
                }
                if (node->right) {
                    reroot(node->right, level + 1,
                           max(outside, level + 1 + leftHeight));
                }
            };

        reroot(root, 0, 0);

        vector<int> result;
        for (int q : queries) result.push_back(ans[q]);
        return result;
    }
};
