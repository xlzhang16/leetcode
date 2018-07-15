class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int orP[n];
        for(int i = 0; i < n; i++)
            orP[i] = i;
        for(int i = 0; i < B.size() - 1; i++){
            for(int j = 0; j < B.size() - 1 - i; j++){
                if(B[j] > B[j + 1]){
                    int tmp = B[j];
                    B[j] = B[j + 1];
                    B[j + 1] = tmp;
                    tmp = orP[j];
                    orP[j] = orP[j + 1];
                    orP[j + 1] = tmp;
                }
            }
        }
        sort(A.begin(), A.end());
        int r = 1;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(A[i] <= B[i]){
                while(r < n){
                    if(A[r] > B[i]){
                        int t = A[i];
                        A[i] = A[r];
                        A[r] = t;
                        break;
                    }
                    r++;
                }
                if(r >= n)
                    break;
            }
            cnt++;
        }
        vector<int> v = A;
        for(int i = 0; i < n; i++){
            v[orP[i]] = A[i];
        }
        return v;
    }
};
