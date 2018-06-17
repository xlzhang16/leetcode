class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> v;
        int t_l = 1;
        for(int i = 1; i < S.length(); i++){
            if(S[i] == S[i - 1])
                t_l++;
            else{
                if(t_l >= 3)
                    v.push_back(vector<int>({i - t_l, i - 1}));
                t_l = 1;
            }
        }
        if(t_l >= 3)
            v.push_back(vector<int>({S.length() - t_l, S.length() - 1}));
        return v;
    }
};
