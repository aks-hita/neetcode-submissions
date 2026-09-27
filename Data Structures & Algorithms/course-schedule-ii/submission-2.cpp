class Solution {
public:
    void dfs(vector<vector<int>>&adj, vector<int>&color, int node, bool& cycle, 
    vector<int>&order){
        if(cycle) return;
        if(color[node]==2) return;
        if(color[node]==1){
            cycle=true;
            return;
        }
        color[node]=1;
        for(int n: adj[node]){
            dfs(adj,color,n,cycle,order);
            if(cycle) break;
        }
        if(!cycle){
            order.push_back(node);
        }
        color[node]=2;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> color(numCourses,0);
        vector<int> order;
        vector<int> finalOrder;
        bool cycle=false;
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i=0;i<numCourses;i++){
            if(color[i]==0 && !cycle){
                order.clear();
                dfs(adj,color,i,cycle,order);
                finalOrder.insert(finalOrder.end(),order.begin(),order.end());
            }
        }
        return (cycle) ? vector<int>{} : finalOrder;
    }
};
