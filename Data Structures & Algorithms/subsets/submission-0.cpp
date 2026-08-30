class Solution {
public:
    void dfs(vector<int>&nums, vector<vector<int>>&result,int i,vector<int>&subset){
        if(i>=nums.size()){
            result.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        dfs(nums,result,i+1,subset);
        subset.pop_back();
        dfs(nums,result,i+1,subset);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>subset;
        vector<vector<int>> result;
        dfs(nums,result,0,subset);
        return result;
    }
};