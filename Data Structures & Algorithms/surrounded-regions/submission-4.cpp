class Solution {
public:
    void dfs(vector<vector<char>>& board,vector<pair<int,int>>& curr,int r, int c,vector<vector<bool>>& visited,bool& touchesBoundary){
        if(r<0||c<0||r==board.size()||c==board[0].size()) return; 
        if(board[r][c]=='X'||visited[r][c]==true) return;
        visited[r][c]=true;
        if(r==0 || c==0 || r==board.size()-1 || c==board[0].size()-1){
            touchesBoundary=true;
        }
        curr.push_back({r,c});
        dfs(board,curr,r+1,c,visited,touchesBoundary);
        dfs(board,curr,r,c+1,visited,touchesBoundary);  
        dfs(board,curr,r-1,c,visited,touchesBoundary);
        dfs(board,curr,r,c-1,visited,touchesBoundary);
    }
    void solve(vector<vector<char>>& board) {
        vector<vector<bool>> 
        visited(board.size(),vector<bool>(board[0].size(),false));
        vector<pair<int,int>>curr;
        bool touchesBoundary=false;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O' && visited[i][j]==false){
                    curr.clear();
                    touchesBoundary=false;
                    dfs(board,curr,i,j,visited,touchesBoundary);
                    if(!touchesBoundary){
                        for(pair<int,int>a:curr){
                            board[a.first][a.second]='X';
                        }
                    }
                } 
            }
        }
    }
};
