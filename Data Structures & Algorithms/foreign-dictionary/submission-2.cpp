class Solution {
public:
    bool add(vector<string>&words, int ind,vector<vector<int>>&adj){
        int i=0;
        string word1=words[ind-1];
        string word2=words[ind];
        while(i!=word1.size() && i!=word2.size() && word1[i]==word2[i]){
            i++;
        }
        if(i==word2.size() && i!=word1.size()) return false;
        if(i!=word1.size()){
            adj[word1[i]-'a'].push_back(word2[i]-'a');
        }
        return true;
    }
    bool cycle(int node,vector<vector<int>>&adj,vector<bool>&exists,vector<int>&col,string &result){
        if(col[node]==1) return true;
        if(col[node]==2) return false;
        col[node]=1;
        for(int neighbor: adj[node]){
            if(cycle(neighbor,adj,exists,col,result)) return true;
        }
        col[node]=2;
        char c=node+'a';
        result.push_back(c);
        return false;
    }
    string foreignDictionary(vector<string>& words) {
        bool safe=true;
        vector<vector<int>> adj(26);
        vector<bool> exists(26, false);
        vector<int> col(26,0);
        string result;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                if(!exists[words[i][j]-'a']) exists[words[i][j]-'a']=true;
            }
        }
        for(int j=1;j<words.size();j++){
            safe=add(words,j,adj);
            if(!safe) return "";
        }
        for(int i=0;i<26;i++){
            if(exists[i] && col[i]==0)
                if(cycle(i,adj,exists,col,result)) return "";
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
