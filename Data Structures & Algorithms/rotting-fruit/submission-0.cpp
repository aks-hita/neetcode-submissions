class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        vector<vector<int>> time(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    time[i][j]=0;
                }
            }
        }
        vector<vector<int>> n={{0,-1},{-1,0},{1,0},{0,1}};
        int max_min=0;
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int new_r=r+n[i][0];
                int new_c=c+n[i][1];
                if(new_r<0 || new_c<0 || new_r==grid.size() || new_c==grid[0].size())
                    continue;
                if(grid[new_r][new_c]!=1) continue;
                time[new_r][new_c]=time[r][c]+1;
                max_min=max(max_min,time[new_r][new_c]);
                grid[new_r][new_c]=2;
                q.push({new_r,new_c});
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return max_min;
    }
};
