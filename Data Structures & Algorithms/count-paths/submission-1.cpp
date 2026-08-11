class Solution {
public:
    void visit(int m, int n, int r, int c, vector<vector<int>> &visited){
        if(r<0 || c<0 || r==m || c==n) return;
        if(visited[r][c]!=0) return;
        visit(m,n,r+1,c,visited);
        visit(m,n,r,c+1,visited);
        if(r<m-1) visited[r][c]=visited[r][c]+visited[r+1][c];
        if(c<n-1) visited[r][c]=visited[r][c]+visited[r][c+1];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>visited(m,vector<int>(n,0));
        visited[m-1][n-1]=1;
        visit(m,n,0,0,visited);
        return visited[0][0];
    }
};
