class Solution { 
    int r, c;
    bool valid(int x, int y){
        return x >= 0 && x < r && y >= 0 && y < c;
    }
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>> ans = M;
        r = M.size();
        c = M[0].size();
        int X[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int Y[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                int tmp = M[i][j];
                int cnt = 1;
                for(int k = 0; k < 8; k++){
                    int x = i + X[k];
                    int y = j + Y[k];
                    if(valid(x, y)){
                        tmp += M[x][y];
                        cnt++;
                    }
                }
                ans[i][j] = tmp / cnt;
            }
        }
        return ans;
    }
};
