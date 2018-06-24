class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> v;
        map<vector<int>, vector<string>> m;
        int idx=0;
        int n=strs.size();
    
        for(int i=0; i< n; i++){
            vector<int> t;
            for(int j=0; j < strs[i].length(); j++){
                t.push_back(strs[i][j]);
                sort(t.begin(), t.end());
            
            }        m[t].push_back(strs[i]);
        }
        for(auto it=m.begin(); it!=m.end(); it++)
            v.push_back(it->second);
        return v;
    }
};
