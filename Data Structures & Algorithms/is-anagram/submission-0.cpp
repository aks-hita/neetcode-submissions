class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> s_alph;
        unordered_map<char,int> t_alph;
        if(s.length() != t.length()){
            return false;
        }
        for(int i=0;i<s.length();i++){
            s_alph[s[i]]++;
        }
        for(int j=0;j<t.length();j++){
            t_alph[t[j]]++;
        }
        if(s_alph==t_alph){
            return true;
        }
        return false;
    }
};
