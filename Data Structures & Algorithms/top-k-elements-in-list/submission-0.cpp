class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        vector<int>result;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        priority_queue<pair<int, int>>pq;
        for(auto j:freq){
            pq.push({j.second, j.first});
        }
        for(int j=0;j<k;j++){
            int ele = pq.top().second;
            pq.pop();
            result.push_back(ele);
        }
        return result;
    }
};
