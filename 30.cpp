class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> v;
        if(s.length() == 0 || words.size() == 0)
            return v;
        map<string, int> cnt;
        for(int i = 0; i < words.size(); i++){
            cnt[words[i]]++;
        }
        int wl = words[0].size();
        for(int i = 0; i < wl; i++){
            int l = i, r = i;
            map<string, int> tcnt;
            int n_vis = 0;
            while(r < s.length()){
                string word = s.substr(r, wl);
                r += wl;
                if(cnt.find(word) == cnt.end()){
                    l = r;
                    tcnt.clear();
                    n_vis = 0;
                }
                else {
                    tcnt[word]++;
                    n_vis++;
                    while(cnt[word] < tcnt[word]){
                        string l_word = s.substr(l, wl);
                        l += wl;
                        tcnt[l_word]--;
                        n_vis--;
                    }
                    if(n_vis == words.size())
                        v.push_back(l);
                    }
            }
        }
        return v;
    }
};
