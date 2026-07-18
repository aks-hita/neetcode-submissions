class Solution{
public:
vector<vector<string>> groupAnagrams(vector<string>& strs){
        vector<vector<string>>result;
        vector<vector<int>>anna(strs.size(),vector<int>(26,0));
        vector<bool>used(strs.size(),0);
        for(int i=0;i<strs.size();i++){
            for(int j=0;j<strs[i].length();j++){
                int curr=strs[i][j]-'a';
                anna[i][curr]++;
            }
        }
        for(int i=0;i<strs.size();i++){
            if(used[i]) continue;
            vector<string> current; current.push_back(strs[i]);
            used[i]=true;
            for(int j=i+1;j<strs.size();j++){
                bool check=true;
                if(used[j]) continue;
                for(int k=0;k<26;k++){
                    if(anna[i][k]!=anna[j][k]){check=false; break;}
                }
                if(check){
                    current.push_back(strs[j]);
                    used[j]=true;
                }
            }
            result.push_back(current);
        }
        return result;
    }
};        