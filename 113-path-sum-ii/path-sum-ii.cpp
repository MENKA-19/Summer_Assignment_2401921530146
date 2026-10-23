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
   vector<vector<int>> anss;
    void pathsum(TreeNode* root,int target,int sum,vector<int> ans){
    
       if(root == NULL)
         return;
         sum += root->val;
         ans.push_back(root->val);
         if(root->left == NULL && root->right == NULL){
              if(sum == target)
                 anss.push_back(ans);
                 return;
         }
            pathsum(root->left,target,sum,ans);
              
            pathsum(root->right,target,sum,ans);
            
    }

  
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> ans;
        
        
        pathsum(root,targetSum,0,ans);
        
        
        return anss;
        
    }
};