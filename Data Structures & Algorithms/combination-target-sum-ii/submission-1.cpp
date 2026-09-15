class Solution {
public:
    void back(vector<int>& curr,
              const vector<int>& nums,
              int target,
              vector<vector<int>>& result,
              int start) {

        if(target == 0) {
            result.push_back(curr);
            return;
        }

        for(int i = start; i < nums.size(); i++) {

            if(i > start && nums[i] == nums[i - 1])
                continue;

            if(nums[i] > target)
                break;

            curr.push_back(nums[i]);

            back(curr, nums, target - nums[i],
                 result, i + 1);

            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<int> curr;
        vector<vector<int>> result;

        back(curr, nums, target, result, 0);

        return result;
    }
};