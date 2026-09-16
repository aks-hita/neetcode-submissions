class Solution {
public:
    void build(vector<vector<int>>&result, vector<int>& curr,vector<bool>&visited,const vector<int>&nums){
        if(curr.size()==nums.size()){
            result.push_back(curr);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!visited[i]){
                visited[i]=true;
                curr.push_back(nums[i]);
                build(result,curr,visited,nums);
                curr.pop_back();
                visited[i]=false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int> curr;
        vector<bool> visited (nums.size(),false);
        build(result,curr,visited,nums);
        return result; 
    }
};
