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
    vector<int> preorder;
    vector<int> inorder;
    int preIndex;
    unordered_map<int,int> inorderIndex;
    TreeNode* build(int L, int R){
        if(L>R) return nullptr;
        TreeNode* curr=new TreeNode(preorder[preIndex]);
        int mid=inorderIndex[preorder[preIndex]];
        preIndex++;
        curr->left=build(L,mid-1);
        curr->right=build(mid+1,R);
        return curr;
    }
    TreeNode* buildTree(vector<int>& p_order, vector<int>& i_order) {
        preIndex=0;
        inorderIndex.clear();
        int L=0,R=i_order.size()-1;
        preorder=p_order; inorder=i_order;
        for(int i=0;i<i_order.size();i++){
            inorderIndex[i_order[i]] = i;
        }
        return build(L,R);
    }
};