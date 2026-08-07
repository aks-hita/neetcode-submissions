class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_prod=1,min_prod=1,old_max=1, old_min=1;
        int ans=INT_MIN;
        for(int curr: nums){
            old_max=max_prod;
            old_min=min_prod;
            max_prod=max({curr*old_min,curr*old_max,curr});
            min_prod=min({curr*old_min,curr*old_max,curr});
            ans=max(ans,max_prod);
        }
        return ans;
    }
};