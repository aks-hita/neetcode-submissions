class Solution {
public:
    void neighbor(vector<vector<char>>& grid,vector<vector<bool>>& visited, int r, int c){
        if(r==grid.size()||c==grid[0].size()||r<0||c<0) return;
        if(grid[r][c]=='0') return;
        if(visited[r][c]) return;
        visited[r][c]=true;
        neighbor(grid,visited,r-1,c);
        neighbor(grid,visited,r+1,c);
        neighbor(grid,visited,r,c-1);
        neighbor(grid,visited,r,c+1);
    }
    int numIslands(vector<vector<char>>& grid) {
       int island_count=0;
       vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
       for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    island_count++;
                    neighbor(grid,visited,i,j);
                }
            }
       }
       return island_count;
    }
};
