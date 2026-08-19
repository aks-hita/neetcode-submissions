class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0, r= matrix.size()-1;
        //find row
        while(l<=r){
            int mid = l + (r-l)/2;
            if(target==matrix[mid][0]) return true;
            else if(matrix[mid][0]<=target) l=mid+1;
            else r=mid-1;
        }
        if(l==0) return false;
        int row=l-1;
        int left=0; int right=matrix[0].size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(target==matrix[row][mid]) return true;
            else if(target<matrix[row][mid]) right=mid-1;
            else left=mid+1;
        }
        return false;
    }
};