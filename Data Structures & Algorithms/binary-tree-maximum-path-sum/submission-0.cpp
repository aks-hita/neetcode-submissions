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
    int path(TreeNode* root, int& global_max){
        if(root==nullptr) return 0;
        int left_cont=max(0,path(root->left,global_max));
        int right_cont=max(0,path(root->right,global_max));
        global_max=max(global_max,root->val+left_cont+right_cont);
        return (root->val+max(left_cont,right_cont));
    }
    int maxPathSum(TreeNode* root) {
        int global_max=INT_MIN;
        path(root,global_max);
        return global_max;
    }
};
