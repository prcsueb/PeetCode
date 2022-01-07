class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int rowLen = mat.size();
        int colLen = mat[0].size();
        vector<int> ans;
        
        if(rowLen==0 && colLen==0) {
            return ans;
        }
        
        int row=0,col=0;
        bool up = true;
        while(row>=0 && row<rowLen && col>=0 && col<colLen) {
            if(up) {
                while(row > 0 && col < colLen-1) {
                    ans.push_back(mat[row][col]);
                    row--;
                    col++;
                }
                //if col is last col
                ans.push_back(mat[row][col]);
                if(col == colLen-1) {
                    row++;
                } else {
                     col++;
                }
            } else {
                while(row < rowLen-1 && col > 0) {
                    ans.push_back(mat[row][col]);
                    row++;
                    col--;
                }
                ans.push_back(mat[row][col]);
                if(row == rowLen-1) {
                    col++;
                } else {
                    row++;
                }
            }
            up=!up;
        }
        
        return ans;
    }
};