class Solution {
public:
    void expand(string &s, int left, int right, int &count){
        while(left>=0 && right<s.size() && s[left]==s[right]){
            count++;
            left--;
            right++;
        }
    }
    int countSubstrings(string s) {
        int left,right,count=0;
        for(int i=0;i<s.size();i++){
            expand(s,i,i+1,count);
            expand(s,i,i,count);
        }
        return count;
    }
};
