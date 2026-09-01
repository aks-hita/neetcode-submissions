class Solution {
public:
    int dfs(vector<int>&nums, int ind, int curr_sum, int& target,vector<vector<int>>&dp,int total){
        if(ind==nums.size()){
            return curr_sum==target;
        }
        if(dp[ind][curr_sum+total]!=-1)
            return dp[ind][curr_sum+total];
        int add=dfs(nums,ind+1,curr_sum+nums[ind],target,dp,total);
        int subtract=dfs(nums,ind+1,curr_sum-nums[ind],target,dp,total);
        return dp[ind][curr_sum+total]=add+subtract;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int total=0;
        for(int num:nums){
            total+=num;
        }
        vector<vector<int>>dp(nums.size(),vector<int>(2*total +1,-1));
        int curr_sum=0;

        return dfs(nums, 0, 0, target, dp, total);
    }
};
