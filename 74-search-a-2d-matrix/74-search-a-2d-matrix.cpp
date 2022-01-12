class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n=mat.size();
        int m=mat[0].size();
        int low=0;
        int high=(n*m)-1;
        //note : 7 is always > 10
        // 20 > 23
        //last cell of any row is greater then first cell of the next row is always true
        while(low<=high) {
            int mid = low+(high-low)/2;
            int row=mid/m;
            int col=mid%m;
            if(mat[row][col]==target) {
                return true;
            } else if(mat[row][col]<target) {
                low=mid+1;
            } else {
                high=mid-1;
            }
        }
        
        return false;
    }
};