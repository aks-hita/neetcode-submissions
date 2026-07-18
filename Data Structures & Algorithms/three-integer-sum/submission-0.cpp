class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        for(int a=0;a<nums.size()-2;a++){
            if(a>0 && nums[a]==nums[a-1]) continue;
            int l=a+1,r=nums.size()-1;
            while(l<r){
                int sum=nums[a]+nums[l]+nums[r];
                if(sum==0){
                    result.push_back({nums[a],nums[l],nums[r]});
                    l++;r--;
                    while(l<r && nums[l]==nums[l-1]){l++;}
                    while(l<r && nums[r]==nums[r+1]){r--;}
                }
                else if(sum<0)l++;
                else r--;
            }
        }
        return result;
    }
};
