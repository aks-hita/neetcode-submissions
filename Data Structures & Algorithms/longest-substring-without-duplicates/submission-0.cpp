class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> cset;
        int l=0; int res=0;

        for(int i=0;i<s.size();i++){
            while(cset.find(s[i])!=cset.end()){
                cset.erase(s[l]);
                l++;
            }
            cset.insert(s[i]);
            res=max(res,i-l+1);
        }
        return res;
    }
};