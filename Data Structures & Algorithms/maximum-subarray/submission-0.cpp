class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum=INT_MIN; int temp_sum=0;
        for(int i=0;i<nums.size();i++){
            temp_sum+=nums[i];
                max_sum=max(max_sum,temp_sum);
            if(temp_sum<0){
                temp_sum=0;
            }
        }
        return max_sum;
    }
};
