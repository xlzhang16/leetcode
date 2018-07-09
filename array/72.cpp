class Solution {
    int min3(int a, int b, int c){
        if(a <= b && a <= c)
            return a;
        if(b <= a && b <= c)
            return b;
        return c;
    }
public:
    int minDistance(string word1, string word2) {
        int r = word1.length(),c = word2.length();
        int dp[r + 1][c + 1];
        for(int i = 0; i <= r; i++){
            dp[i][0] = i;
        }
        for(int j = 0; j <= c; j++){
            dp[0][j] = j;
        }
        for(int i = 1; i <= r; i++){
            for(int j = 1; j <= c; j++){
                int tmp = word1[i - 1] == word2[j - 1] ? 0:1;    
                dp[i][j] = min3(dp[i][j - 1] + 1, dp[i - 1][j] + 1, dp[i - 1][j - 1] + tmp);
            }
        }
        return dp[r][c];
    }
};
