class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord==endWord) return 1;
        int n=wordList.size();
        vector<bool> visited (n+1,false);
        unordered_map<string,int> words;
        for(int s=0;s<wordList.size();s++){
            words.insert({wordList[s],s});
        }
        int distance=1;
        queue<int> q;
        q.push(n);
        visited[n]=true;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int ind=q.front();
                string curr=(ind==n)? beginWord : wordList[ind];
                vector<int> neighbor;
                if(curr==endWord){
                    return distance;
                }
                string temp=curr;
                for(int i=0;i<curr.size();i++){
                    for(int j=0;j<26;j++){
                        if(temp[i]==j+'a') continue;
                        temp[i]='a'+j;
                        if(words.count(temp)) neighbor.push_back(words[temp]);
                    }
                    temp=curr;
                }
                for(int n:neighbor){
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