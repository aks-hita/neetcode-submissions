class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0)
                    q.push({i,j});
            }
        }
        int i=0;
        vector<vector<int>> n={{-1,0},{0,-1},{1,0},{0,1}};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            for(int j=0;j<4;j++){
                int new_r=r+n[j][0];
                int new_c=c+n[j][1];
                if(new_r<0 || new_c<0 || new_r == grid.size()|| new_c == grid[0].size()) continue;
                if(grid[new_r][new_c]!=INT_MAX) continue;
                grid[new_r][new_c]=grid[r][c]+1;
                q.push({new_r,new_c});
            }
            i++;
            q.pop();
        }
    }
};
