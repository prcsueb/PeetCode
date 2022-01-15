class Solution {
public:
    vector<vector<int>> dir = {{-1,0},{0,-1},{1,0},{0,1}};
    void dfs(vector<vector<int>>& heights, int row, int col, vector<vector<int>> &grid) {
        grid[row][col]=1;
        for(auto d : dir) {
            int newRow = row + d[0];
            int newCol = col + d[1];
            if(newRow >= 0 && newCol >= 0 && newRow < heights.size() && newCol < heights[0].size() && heights[row][col]<=heights[newRow][newCol] && grid[newRow][newCol]==0) {
                dfs(heights,newRow,newCol,grid);
            }
        }
    }
    
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row=heights.size();
        int col=heights[0].size();
        vector<vector<int>> pacific(row,vector<int>(col,0));
        vector<vector<int>> atlantic(row,vector<int>(col,0));
        //dfs on left col and first row
        for(int i=0;i<col;i++) {
            dfs(heights,0,i,pacific);
        }
        
        for(int i=0;i<row;i++) {
            dfs(heights,i,0,pacific);
        }
        
        //dfs on right col and last row
        for(int i=0;i<col;i++) {
            dfs(heights,row-1,i,atlantic);
        }
        
        for(int i=0;i<row;i++) {
            dfs(heights,i,col-1,atlantic);
        }
        
        vector<vector<int>> ans;
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                if(pacific[i][j] == 1 && atlantic[i][j] == 1) {
                    ans.push_back({i,j});
                }
            }
        }
        
        return ans;
    }
};