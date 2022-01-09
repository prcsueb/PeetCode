class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if(row == 1) {
            return true;
        }
        int col = matrix[0].size();
        for(int i=row-2;i>=0;i--) {
            for(int j=0;j<col-1;j++) {
                if(matrix[i+1][j+1] == matrix[i][j]) {
                    continue;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};