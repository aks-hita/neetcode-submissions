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

class Codec {
public:
    string data;
    string ans;
    string encode(TreeNode* root){
        string s="1";
        int temp=root->val+1000;
        for(int i=10;i>-1;i--){
            if((temp >> i) & 1) s+="1";
            else s+="0";
        }
        return s;
    }
    void order(TreeNode* root){
        if(root==nullptr){ans+="000000000000";return;}
        ans+=encode(root);
        order(root->left);
        order(root->right);
        return;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ans.clear();
        order(root);
        return ans;
    }
    TreeNode* decode(int ind){
        int val=0;
        for(int i=1;i<12;i++){
            val=val*2+(data[ind+i]-'0');
        }
        TreeNode* ptr=new TreeNode(val-1000);
        return ptr;
    }
    // Decodes your encoded data to tree.
    TreeNode* build(int& ind){
        if (ind >= data.size()) return nullptr;
        if(data[ind]=='0'){ind+=12;return nullptr;}
        TreeNode* curr=decode(ind);
        ind+=12;
        curr->left=build(ind);
        curr->right=build(ind);
        return curr;
    }
    TreeNode* deserialize(string s) {
        data=s;
        if(data == "000000000000") return nullptr;
        int ind=0;
        TreeNode* root=build(ind);
        return root;
    }
};
