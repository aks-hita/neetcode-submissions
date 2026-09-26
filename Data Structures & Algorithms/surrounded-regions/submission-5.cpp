class Solution {
public:
    void dfs(vector<vector<char>>& board,vector<pair<int,int>>& curr,int r, int c, bool& touchesBoundary){
        if(r<0||c<0||r==board.size()||c==board[0].size()) return; 
        if(board[r][c]!='O') return;
        board[r][c]='#';
        if(r==0 || c==0 || r==board.size()-1 || c==board[0].size()-1){
            touchesBoundary=true;
        }
        curr.push_back({r,c});
        dfs(board,curr,r+1,c,touchesBoundary);
        dfs(board,curr,r,c+1,touchesBoundary);  
        dfs(board,curr,r-1,c,touchesBoundary);
        dfs(board,curr,r,c-1,touchesBoundary);
    }
    void solve(vector<vector<char>>& board) {
        vector<vector<bool>> 
        visited(board.size(),vector<bool>(board[0].size(),false));
        vector<pair<int,int>>curr;
        bool touchesBoundary=false;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O'){
                    curr.clear();
                    touchesBoundary=false;
                    dfs(board,curr,i,j,touchesBoundary);
                    if(!touchesBoundary){
                        for(pair<int,int>a:curr){
                            board[a.first][a.second]='X';
                        }
                    }
                    else{
                        for(pair<int,int>a:curr){
                            board[a.first][a.second]='O';
                        }
                    }
                } 
            }
        }
    }
};
