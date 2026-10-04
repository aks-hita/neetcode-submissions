class Solution {
public:
    bool connected(vector<vector<int>>& neighbor, int node, int n,vector<int>& 
    visited){
        if(node == n) return true;
        if(visited[node]==1) return false;
        visited[node]=1;
        for(int i:neighbor[node]){
            if(connected(neighbor, i, n, visited)) return true;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n= edges.size();
        vector<vector<int>> neighbor (n+1);
        for(vector<int> n: edges){
            vector<int> visit(edges.size()+1,0);
            if(connected(neighbor,n[0],n[1], visit)){
                return n;
            }
            neighbor[n[0]].push_back(n[1]);
            neighbor[n[1]].push_back(n[0]);
        }
        return {};
    }
};
