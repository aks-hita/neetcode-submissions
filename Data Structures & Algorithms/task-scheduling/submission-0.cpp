class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<vector<int>>freq(26,vector<int>(2,0));
        for(char i:tasks){
            freq[i-'A'][0]++;
            freq[i-'A'][1]=-1;
        }
        int cycles=0; 
        priority_queue<pair<int,int>> pq;
        queue<int> q;
        for(int i=0;i<26;i++){
            if(freq[i][0]>0){
                pq.push({freq[i][0],i});
            }
        }
        while(!q.empty() || !pq.empty()){
            cycles++;
            while(!q.empty() && cycles>=freq[q.front()][1]+n+1){
                pq.push({freq[q.front()][0],q.front()});
                q.pop();
            }
            if(pq.empty()) continue;
            auto [count, task] = pq.top();
            pq.pop();
            freq[task][1]=cycles;
            freq[task][0]--;
            if(freq[task][0]>0){
                q.push(task);
            }
        }
        return cycles;
    }
};
