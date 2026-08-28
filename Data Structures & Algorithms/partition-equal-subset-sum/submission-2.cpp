class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.size()<=1) return false;
        int total_sum=0;
        for(int i=0;i<nums.size();i++){
            total_sum+=nums[i];
        }
        if(total_sum%2!=0) return false;
        int target=total_sum/2;
        vector<bool> dp(target+1,false);
        dp[0]=true;
        for(int i=0;i<nums.size();i++) {
            for(int s = target; s >= nums[i]; s--) {
                dp[s] = dp[s] || dp[s - nums[i]];
            }
        }
        return dp[target];
    }
};
