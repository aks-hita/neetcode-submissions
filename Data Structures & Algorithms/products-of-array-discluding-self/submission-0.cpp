class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums){
        int prod=1;
        int zeroCount=0;
        for(int i=0;i<nums.size();i++){
            if(nums.at(i) != 0) prod=prod*nums.at(i);
            else zeroCount++;
        }
        vector<int>res(nums.size());
        for(int j=0;j<nums.size();j++){
            if(zeroCount > 1) res[j] = 0;
            else if(zeroCount == 1) res[j] = (nums.at(j) == 0) ? prod : 0;
            else res[j]=(prod/nums.at(j));
        }
        return res;
    }
};