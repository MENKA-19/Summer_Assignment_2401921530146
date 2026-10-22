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
    int cameras = 0;

    // 0 = Not covered
    // 1 = Has camera
    // 2 = Covered
    int dfs(TreeNode* root) {
        if (root == NULL) {
            return 2;
        }

        int left = dfs(root->left);
        int right = dfs(root->right);

        // If any child is not covered, place a camera here
        if (left == 0 || right == 0) {
            cameras++;
            return 1;
        }

        // If any child has a camera, current node is covered
        if (left == 1 || right == 1) {
            return 2;
        }

        // Both children are covered, but current node is not
        return 0;
    }

    int minCameraCover(TreeNode* root) {
        if (dfs(root) == 0) {
            cameras++;
        }

        return cameras;
    }
};
