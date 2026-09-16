class Solution {
public:
    void dfs(vector<vector<int>>&result, vector<int>&curr,const vector<int>&nums,int ind){
        if(ind==nums.size()){
            result.push_back(curr);
            return;
        }
        curr.push_back(nums[ind]);
        dfs(result,curr,nums,ind+1);
        curr.pop_back();
        while(ind+1<nums.size() && nums[ind]==nums[ind+1]){
            ind++;
        }
        dfs(result,curr,nums,ind+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>result;
        vector<int>curr;
        dfs(result,curr,nums,0);
        return result;
    }
};
