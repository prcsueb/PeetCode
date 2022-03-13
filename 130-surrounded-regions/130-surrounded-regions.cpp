class Solution {
public:
    
    //mark boundary connected #
    void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<int>> &dir) {
        grid[i][j] = '#';
        for(auto d : dir) {
            int newX = i + d[0];
            int newY = j + d[1];
            if(newX >= 0 && newY >= 0 && newX < grid.size() && newY<grid[0].size() && grid[newX][newY] == 'O') {
                dfs(newX, newY, grid, dir);
            }
        }
    }
    void solve(vector<vector<char>>& grid) {
        vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j] == 'O' && (i == 0 || i == grid.size()-1 || j == 0 || j == grid[0].size()-1)) {
                    dfs(i, j, grid, dir);
                }
            }
        }
        
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j] == 'O') {
                    grid[i][j] = 'X';
                } else if(grid[i][j] == '#') {
                    grid[i][j] = 'O';
                }
            }
        }
        
        
        
    }
};