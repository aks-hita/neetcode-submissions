class Solution {
public:
    void dfs(int node, vector<vector<int>>&adj_list,vector<bool>&visited){
        visited[node]=true;
        for(int neighbor:adj_list[node]){
            if(!visited[neighbor]){
                dfs(neighbor,adj_list,visited);
            }
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1) return false;
        vector<bool> visited(n,false);
        vector<vector<int>> adj_list(n);
        for(int i=0;i<edges.size();i++){
            adj_list[edges[i][0]].push_back(edges[i][1]);
            adj_list[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(0,adj_list,visited);
        for(int i=0;i<n;i++){
            if(!visited[i]) return false;
        }
        return true;
    }
};
