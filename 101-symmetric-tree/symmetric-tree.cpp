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
//   bool isSame(TreeNode* p,TreeNode* q){
//      if(p == NULL || q == NULL)
//         return p == q;
//         bool lefts = isSame(p->left,q->right);
//          bool rights = isSame(p->right,q->left);
//          return lefts && rights && p->val == q->val; 

//   }

    bool same(TreeNode* root1,TreeNode* root2){
       if(root1 == NULL && root2 == NULL)
           return true;
          if(root1 && !root2)
           return false;
           if(root2 && !root1)
            return false;
            if(root1 && root2){
                if(root1->val != root2->val)
                    return false;
            }
            return same(root1->left,root2->right) && same(root1->right,root2->left);

        
             
   }
    bool isSymmetric(TreeNode* root) {
        bool result = same(root->left,root->right);
        return result;
        
    }
};