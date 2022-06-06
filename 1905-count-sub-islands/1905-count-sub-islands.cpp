class Solution {
public:
    vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int sr, int sc) {
        bool ans = grid2[sr][sc] == grid1[sr][sc];
        grid2[sr][sc] = 0;
        
        for(auto &d : dir) {
            int newRow = sr + d[0];
            int newCol = sc + d[1];
            if(newRow >= 0 && newCol >= 0 && newRow < grid2.size() && newCol < grid2[0].size() && grid2[newRow][newCol] == 1) {
                ans = dfs(grid1, grid2, newRow, newCol) && ans;
            }
        }
        return ans;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int count = 0;
        for(int i=0;i<grid2.size();i++) {
            for(int j=0;j<grid2[0].size();j++) {
                if(grid2[i][j] == 1) {
                    if(dfs(grid1, grid2, i, j)) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};