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
        vector<vector<int>> dup=matrix;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(dup[i][j]==0)
                    zero(matrix,i,j);
            }
        }
    }
};
