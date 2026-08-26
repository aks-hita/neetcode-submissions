class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> hash;
        for(int i:nums){
            if(hash.contains(i)) return i;
            hash.insert(i);
        }
        return -1;
    }
};
