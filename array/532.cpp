class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int, int> cnt;
        for(int i = 0; i < nums.size(); i++){
            cnt[nums[i]]++;
        }
        int n = 0;
        for(auto it = cnt.begin(); it != cnt.end(); it++){
            if(k == 0){
                if(it->second > 1)
                    n++;
            }
            else if(k > 0){
                if(cnt.find(it->first + abs(k)) != cnt.end())
                    n++;
            }
        }
        return n;
    }
};
