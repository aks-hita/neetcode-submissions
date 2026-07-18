class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> check;
        for(int i=0;i<nums.size();i++){
            check.insert(nums[i]);
        }
        int maxLen=0;
        for(int num : check) {
            if(check.find(num - 1) == check.end()) {   // start of sequence
                int curr = num;
                int len = 1;

                while(check.find(curr + 1) != check.end()) {
                    curr++;
                    len++;
                }

                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};
