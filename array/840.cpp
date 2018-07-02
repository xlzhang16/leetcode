class Solution {
    bool valid(vector<vector<int>>& grid, int x, int y){
        map<int, int> cnt;
        for(int i = x - 1; i <= x + 1; i++){
            for(int j = y - 1; j <= y + 1; j++){
                if(grid[i][j] > 9 || grid[i][j] == 0)
                    return false;
                cnt[grid[i][j]]++;
                if(cnt[grid[i][j]] > 1)
                    return false;
            }
        }
        int sum = grid[x - 1][y] + grid[x + 1][y] + grid[x][y];
        if(grid[x - 1][y - 1] + grid[x - 1][y] + grid[x - 1][y + 1] != sum)
            return false;
        if(grid[x][y - 1] + grid[x][y] + grid[x][y + 1] != sum)
            return false;
        if(grid[x + 1][y - 1] + grid[x + 1][y] + grid[x + 1][y + 1] != sum)
            return false;
        if(grid[x - 1][y - 1] + grid[x][y - 1] + grid[x + 1][y - 1] != sum)
            return false;
        if(grid[x - 1][y] + grid[x][y] + grid[x + 1][y] != sum)
            return false;
        if(grid[x - 1][y + 1] + grid[x][y + 1] + grid[x + 1][y + 1] != sum)
            return false;
        if(grid[x - 1][y - 1] + grid[x][y] + grid[x + 1][y + 1] != sum)
            return false;
        if(grid[x + 1][y - 1] + grid[x][y] + grid[x - 1][y + 1] != sum)
            return false;
        return true;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        if(grid.size() == 0)
            return ans;
        for(int i = 1; i < grid.size() - 1; i++){
            for(int j = 1; j < grid[0].size() - 1; j++)
                if(valid(grid, i, j))
                    ans++;
        }
        return ans;
    }
};
