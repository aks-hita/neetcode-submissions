class Solution {
public:
    void zero(vector<vector<int>>& matrix, int r, int c){
        for(int i=0;i<matrix.size();i++){
            matrix[i][c]=0;
        }
        for(int i=0;i<matrix[0].size();i++){
            matrix[r][i]=0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> to_change;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    to_change.push_back({i,j});
                }
            }
        }
        for(int n=0;n<to_change.size();n++){
            zero(matrix,to_change[n][0],to_change[n][1]);
        }
    }
};
