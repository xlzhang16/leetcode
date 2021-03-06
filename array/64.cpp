class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size();
        if(r == 0)
            return 0;
        int c = grid[0].size();
        int dp[r][c];
        dp[0][0] = grid[0][0];
        for(int i = 1; i < r; i++)
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        for(int i = 1; i < c; i++)
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        int Min = 0x7fffffff;
        for(int i = 1; i < r; i++)
            for(int j = 1; j < c; j++){
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
                if(Min > dp[i][j])
                    Min = dp[i][j];
            }
        return dp[r - 1][c - 1];
    }
};
