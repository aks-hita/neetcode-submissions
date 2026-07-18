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
    bool dfs(TreeNode* root, int lim_min, int lim_max){
        if(root==nullptr) return true;
        if(root->val<= lim_min || root->val>= lim_max){
            return false;
        }
        return (dfs(root->left,lim_min,root->val) && (dfs(root->right,root->val,lim_max)));
    }
    bool isValidBST(TreeNode* root) {
        int lim_min=INT_MIN, lim_max=INT_MAX;
        return dfs(root,lim_min,lim_max);
    }
};
