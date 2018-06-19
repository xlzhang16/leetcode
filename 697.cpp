class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int, int> cnt, start, end;
        int max_cnt = 0;
        for(int i = 0; i < nums.size();i++){
            int x = nums[i];
            if(start.find(x) == start.end())
                start[x] = i;
            end[x] = i;
            cnt[x]++;
            max_cnt = max(max_cnt, cnt[x]);
        }
        int min_l = nums.size();
        for(auto it = start.begin(); it != start.end(); it++){
            if(cnt[it->first] == max_cnt)
                min_l = min(min_l, end[it->first] - it->second + 1);
        }
        return min_l;
    }
};
