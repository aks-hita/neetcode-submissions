class Solution {
public:
    bool compare(string word1, string word2){
        if(word1.size()!=word2.size()) return false;
        bool flag=false;
        for(int i=0;i<word1.size();i++){
            if(flag){
                if(word1[i]!=word2[i]) return false;
            }else{
                if(word1[i]!=word2[i]) flag=true;
            }
        }
        return flag;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord==endWord) return 0;
        int n=wordList.size();
        vector<bool> visited (n+1,false);
        vector<vector<int>> transform(n+1);
        for(int i=0; i<n;i++){
            for(int j=i+1; j<n;j++){
                if(compare(wordList[i],wordList[j])){
                    transform[i].push_back(j);
                    transform[j].push_back(i);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(compare(beginWord,wordList[i])){
                transform[n].push_back(i);
            }
        }
        int distance=1;
        queue<int> q;
        q.push(n);
        visited[n]=true;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int ind=q.front();
                if(ind!=n && wordList[ind]==endWord){
                    return distance;
                }
                for(int n:transform[ind]){
                    if(!visited[n]){
                        visited[n]=true;
                        q.push(n);
                    }
                }
                q.pop();
            }
            distance++;
        }
        return 0;
    }
};
