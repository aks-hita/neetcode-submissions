class Solution {
public:
    bool check_square(vector<vector<char>>& board, int r, int c){
        vector<bool> num(9, false);
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[r+i][c+j] == '.')
                    continue;

                int x = board[r+i][c+j] - '1';
                if(num[x])
                    return false;

                num[x] = true;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> num(9,false);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.')
                    continue;
                int x = board[i][j] - '1';
                if(num[x])
                    return false;
                num[x] = true;
            }
            for(int k=0;k<9;k++){
                num[k]=false; 
            }
        }
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[j][i] == '.')
                    continue;
                int x = board[j][i] - '1';
                if(num[x])
                    return false;
                num[x] = true;
            }
            for(int k=0;k<9;k++){
                num[k]=false; 
            }
        }
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(i%3==0 && j%3==0){
                    if(!check_square(board,i,j)) return false;
                }
            }
        }
        return true;
    }
};
