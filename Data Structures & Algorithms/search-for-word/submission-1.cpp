class Solution {
public:
    vector<vector<char>>board;
    string word;
    bool search(vector<vector<bool>>& visited, int index, int r, int c){
        bool found=false;
        if(r>=board.size()||c>=board[0].size() || r<0 ||c<0) return false;
        if(visited[r][c] || board[r][c]!=word[index]) return false;
        visited[r][c]=true;
        if(index==word.size()-1){visited[r][c]=false;return true;}
        found=(search(visited,index+1,r-1,c) || search(visited,index+1,r+1,c) ||
        search(visited,index+1,r,c-1) || search(visited,index+1,r,c+1));
        visited[r][c]=false;
        return found;
    }
    bool first_search(vector<vector<bool>>& visited){
        int index=0;
        for(int i=0;i<board.size();i++){  
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    if(search(visited,index,i,j)) return true;
                }
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& q_board, string q_word) {
        board=q_board; word=q_word;
        vector<vector<bool>>visited(board.size(),vector<bool>(board[0].size(),false));
        return first_search(visited);
    }
};
