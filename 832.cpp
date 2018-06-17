class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int r = A.size();
        int c = A[0].size();
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c / 2; j++){
                int t = A[i][c - 1 - j];
                A[i][c - 1 - j] = 1 - A[i][j];
                A[i][j] = 1 - t;
            }
            if(c % 2 == 1)
                A[i][c / 2] = 1 - A[i][c / 2];
        }
        return A;
    }
};
