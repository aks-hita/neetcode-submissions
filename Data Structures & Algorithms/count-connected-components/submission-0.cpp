class Solution {
public:
    void dfs(int node, const vector<vector<int>>& adj_list, vector<bool>&visited){
        if(visited[node]) return;
        visited[node]=true;
        for(int neighbor: adj_list[node]){
            dfs(neighbor,adj_list,visited);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj_list(n);
        vector<bool> visited(n,false);
        for(int i=0;i<edges.size();i++){
            adj_list[edges[i][0]].push_back(edges[i][1]);
            adj_list[edges[i][1]].push_back(edges[i][0]);
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,adj_list,visited);
                count++;
            }
        }
        return count;
    }
};
