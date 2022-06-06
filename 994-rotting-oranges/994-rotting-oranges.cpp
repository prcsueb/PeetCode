class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j] == 1) {
                    fresh++;
                }
                else if(grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        
        if(fresh == 0) return 0;
        
        vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        int level = -1;
        while(!q.empty()) {
            int size = q.size();
            ++level;
            while(size--) {
                pair<int, int> front = q.front();
                q.pop();
                for(auto &d : dir) {
                    int newRow = front.first + d[0];
                    int newCol = front.second + d[1];
                    if(newRow >= 0 && newCol >= 0 && newRow < grid.size() && newCol < grid[0].size() && grid[newRow][newCol] == 1) {
                        grid[newRow][newCol] = 2;
                        q.push({newRow, newCol});
                        fresh--;
                    }
                }
            }
        }
        if(fresh != 0) return -1;
        return level;
    }
};