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
    void traverse(TreeNode* root, int &maxdep, int &curr){
        if(!root){maxdep=max(maxdep,curr); return;}
        curr++;
        traverse(root->right,maxdep,curr);
        traverse(root->left,maxdep,curr);
        curr--;
    }
    int maxDepth(TreeNode* root) {
        int max_depth=0,curr=0;
        traverse(root,max_depth,curr);
        return max_depth;
    }
};
