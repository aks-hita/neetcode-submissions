class Solution {
public:
    bool dfs(vector<int>&nums, int ind, int target){
        if(target==0) return true;
        if(ind==nums.size()) return false;
        if(nums[ind] <= target && dfs(nums, ind + 1, target - nums[ind]))
            return true;
        return (dfs(nums,ind+1,target-nums[ind]) || dfs(nums,ind+1,target));
    }
    bool canPartition(vector<int>& nums) {
        if(nums.size()<=1) return false;
        int total_sum=0;
        for(int i=0;i<nums.size();i++){
            total_sum+=nums[i];
        }
        if(total_sum%2!=0) return false;
        return dfs(nums,0,total_sum/2);
    }
};
