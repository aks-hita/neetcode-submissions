class Solution {
public:
    int robber(vector<int>&nums,int l,int r){
        int n=r-l+1;
        vector<int> dp(n);
        if(n<2){
            return nums[l];
        }
        dp[0]=nums[l];
        dp[1]=max(nums[l+1],dp[0]);
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i+l]);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        if(nums.size()<2){
            return nums[0];
        }
        return(max (robber(nums,0,nums.size()-2),robber(nums,1,nums.size()-1)));
    }
};
