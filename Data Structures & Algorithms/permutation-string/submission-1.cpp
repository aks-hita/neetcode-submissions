class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;
        vector<int> count_1(26, 0);
        vector<int> count_2(26, 0);
        for(char c: s1){
            count_1[c-'a']++;
        }
        int left=0, right=s1.size()-1;
        for(int i=left;i<=right;i++){
            count_2[s2[i]-'a']++;
        }
        if(count_1==count_2) return true;
        while(right<s2.size()-1){
            count_2[s2[left]-'a']--;
            left++; right++;
            count_2[s2[right]-'a']++;
            if(count_1==count_2) return true;
        }
        return false;
    }
};
