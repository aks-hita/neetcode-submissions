class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>result;
        deque<int>dq;
        for(int right=0;right <nums.size();right++){
            while(!dq.empty() && dq.front()<=right-k){
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()]<=nums[right]){
                dq.pop_back();
            }
            dq.push_back(right);
            if(right>=k-1){
                result.push_back(nums[dq.front()]);
            }
        } 
        return result;
    }
};
