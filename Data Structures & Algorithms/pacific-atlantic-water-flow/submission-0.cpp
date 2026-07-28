class Solution {
public:
    void process_pac(vector<vector<int>>& heights,vector<vector<bool>>&pac,int r,int c){
        if(r==heights.size()||c==heights[0].size()||r<0||c<0) return;
        if(pac[r][c]) return;
        pac[r][c]=true;
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        for(int i=0;i<4;i++){
            int newR=r+dr[i];
            int newC=c+dc[i];
            if(newR==heights.size()||newC==heights[0].size()||newR<0||newC<0) continue;
            else if(heights[newR][newC]>=heights[r][c] && !pac[newR][newC]){
                process_pac(heights,pac,newR,newC);
            }
        }
    }
    void process_at(vector<vector<int>>& heights,vector<vector<bool>>&at,vector<vector<bool>>&pac,int r,int c,vector<vector<int>>&result){
        if(r==heights.size()||c==heights[0].size()||r<0||c<0) return;
        if(at[r][c]) return;
        at[r][c]=true;
        if(pac[r][c]) result.push_back({r,c});
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        for(int i=0;i<4;i++){
            int newR=r+dr[i];
            int newC=c+dc[i];
            if(newR==heights.size()||newC==heights[0].size()||newR<0||newC<0) continue;
            else if(heights[newR][newC]>=heights[r][c] && !at[newR][newC]){
                process_at(heights,at,pac,newR,newC,result);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>> pac(heights.size(),vector<bool>(heights[0].size(),false));
        vector<vector<bool>> at(heights.size(),vector<bool>(heights[0].size(),false));
        int n=heights.size(); int m=heights[0].size();
        for(int i=0;i<m;i++){
            process_pac(heights,pac,0,i);
        }
        for(int i=0;i<n;i++){
            process_pac(heights,pac,i,0);
        }
        vector<vector<int>>result;
        for(int i=0;i<m;i++){
            process_at(heights,at,pac,n-1,i,result);
        }
        for(int i=0;i<n;i++){
            process_at(heights,at,pac,i,m-1,result);
        }
        return result;
    }
};
