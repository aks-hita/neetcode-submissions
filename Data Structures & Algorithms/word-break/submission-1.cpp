class Trie{
    public:
    vector<Trie*> alph;
    bool isEndOfWord=false;
    Trie(){
        for(int i=0;i<26;i++)
            alph.push_back(nullptr);
    }
    void add_word(string s){
        Trie* root=this;
        for(char c: s){
            if(root->alph[c-'a']==nullptr){
                Trie* temp=new Trie;
                root->alph[c-'a']=temp;
            }
            root=root->alph[c-'a'];
        }
        root->isEndOfWord=true;
    }
    void search(string s,int ind,vector<bool>&dp){
        Trie* curr=this;
        for(int i=ind;i<s.size();i++){
            ind++;
            if(curr->alph[s[i]-'a']==nullptr) break;
            curr=curr->alph[s[i]-'a'];
            if(curr->isEndOfWord) dp[i+1]=true;
        }
    }
};
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1,false);
        dp[0]=true;
        Trie root;
        for(string str:wordDict){
            root.add_word(str);
        }
        bool check;
        for(int i=0;i<s.size();i++){
            if(dp[i]){
                root.search(s,i,dp);
            }
        }
        return dp[s.size()];
    }
};
