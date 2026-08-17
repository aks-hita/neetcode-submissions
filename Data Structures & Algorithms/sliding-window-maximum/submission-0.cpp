class Solution {
public:
    int find_max(vector<int>&nums, int left, int right){
        if(right>=nums.size()) return -1;
        int window_max=nums[left];
        for(int i=left+1;i<=right;i++){
            window_max=max(window_max,nums[i]);
        }
        return window_max;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>result;
        if(k>nums.size()) return {};
        int left=0; int right=k-1;
        int wind_max=find_max(nums,left,right);
        result.push_back(wind_max);
        while(right+1<nums.size()){
            left++; right++;
            if(wind_max==nums[left-1])
                wind_max=find_max(nums,left,right);
            else{
                wind_max=max(wind_max,nums[right]);
            }
            result.push_back(wind_max);
        }
        return result;
    }
};
