class Solution {
public:
    void back(vector<int>&curr,vector<int>&nums, int target, vector<vector<int>>&result,int start){
        if(target==0){
            result.push_back(curr);
            return;
        }
        for(int i=start;i<nums.size();i++){
            if(target-nums[i]>=0){
                curr.push_back(nums[i]);
                target-=nums[i];
                back(curr,nums,target,result,i);
                curr.pop_back();
                target+=nums[i];
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>curr;
        vector<vector<int>>result;
        back(curr,nums,target,result,0);
        return result;
    }
};
