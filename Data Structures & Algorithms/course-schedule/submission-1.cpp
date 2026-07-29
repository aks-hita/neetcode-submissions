class Solution {
public:
    bool dfs(vector<vector<int>>&adj,vector<string>&color,int curr){
        if(color[curr]=="gray") return false;
        if(color[curr]=="black") return true;
        color[curr]="gray";
        bool result=true;
        for(int i=0;i<adj[curr].size();i++){
            result=dfs(adj,color,adj[curr][i]);
            if(!result) return false;
        }
        color[curr]="black";
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        bool ans=true;
        vector<vector<int>>adj(numCourses);
        vector<string>color(numCourses,"white");
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int j=0;j<numCourses;j++){
            if(color[j]=="white"){
                ans=dfs(adj,color,j);
            }
            if(!ans) return false;
        }
        return true;
    }
};
