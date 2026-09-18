class Solution {
public:
    void dfs(const vector<vector<int>>&grid, int r, int c, vector<vector<bool>>& visited, int& curr,int& maxArea){
        if(r<0 || c<0|| r==grid.size()||c==grid[0].size()) return;
        if(grid[r][c]==0) return;
        if(visited[r][c]) return;
        visited[r][c]=true;
        curr++;
        maxArea=max(maxArea,curr);
        dfs(grid,r+1,c,visited,curr,maxArea);
        dfs(grid,r-1,c,visited,curr,maxArea);
        dfs(grid,r,c+1,visited,curr,maxArea);
        dfs(grid,r,c-1,visited,curr,maxArea);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea=0;
       vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));
       for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    int curr=0;
                    dfs(grid,i,j,visited,curr,maxArea);
                }
            }
       }
       return maxArea;
    }
};
