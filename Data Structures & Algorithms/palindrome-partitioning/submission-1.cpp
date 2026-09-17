class Solution {
public:
    bool isPalindrome(const string& s, int l, int r){
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    void dfs(const string& s, int j,int i, vector<string> &temp, vector<vector<string>>&result){
        if(i==s.size()){
            if(j==s.size()){
                result.push_back(temp);
            }
            return;
        }
        if(isPalindrome(s,j,i)){
            temp.push_back(s.substr(j,i-j+1));
            dfs(s,i+1,i+1,temp,result);
            temp.pop_back();
        } 
        dfs(s,j,i+1,temp,result);
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string>temp;
        dfs(s,0,0,temp,result);
        return result;
    }
};
