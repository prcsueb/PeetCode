class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int row=0;
        int col=0;
        int n=mat.size();
        int m=mat[0].size();
        int dir=1;
        vector<int> v;
        while(row<n && col<m) {
            if(dir==1) {
                v.push_back(mat[row][col]);
                if(col==m-1) {
                    dir=-1;
                    row++;
                } else if(row==0) {
                    dir=-1;
                    col++;
                } else {
                    row--; col++;
                }
            } else {
                v.push_back(mat[row][col]);
                if(row==n-1) {
                    dir=1;
                    col++;
                }
                else if(col==0) {
                    dir=1;
                    row++;
                } else {
                    row++; col--;
                }
            }
        }
        cout << row << " , " << col << endl;
        return v;
    }
};