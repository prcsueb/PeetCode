class Solution {
public:
    bool dfs(int i, int j, vector<vector<int>> &grid1, vector<vector<int>> &grid2, vector<vector<int>> &dir) {
        bool ans = grid2[i][j] == grid1[i][j];
        grid2[i][j]=0;
        for(auto d : dir) {
            int newX = i + d[0];
            int newY = j + d[1];
            if(newX >= 0 && newY >= 0 && newX < grid2.size() && newY<grid2[0].size() && grid2[newX][newY] == 1) {
                ans = dfs(newX, newY, grid1, grid2, dir) && ans;
            } 
        }
        return ans;
    }
    
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        int counter=0;
        for(int i=0;i<grid2.size();i++) {
            for(int j=0;j<grid2[0].size();j++) {
                if(grid2[i][j] == 1) {
                    bool comp = dfs(i, j, grid1, grid2, dir);
                    if(comp) counter++;
                }
            }
        }
        return counter;
    }
};