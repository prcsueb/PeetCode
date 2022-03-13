class Solution {
public:
    
    void dfs(int i, int j, vector<vector<int>> &grid, int &size, vector<vector<int>> &dir) {
        grid[i][j] = 0;
        ++size;
        for(auto d : dir) {
            int newX = i + d[0];
            int newY = j + d[1];
            if(newX < grid.size() && newY<grid[0].size() && grid[newX][newY] == 1) {
                dfs(newX, newY, grid, size, dir);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j] == 1) {
                    int size=0;
                    dfs(i, j, grid, size, dir);
                    ans=max(ans, size); 
                }
            }
        }
        
        return ans;
    }
};