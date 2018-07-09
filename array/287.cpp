class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int cnt[n + 1] = {0};
        for(int i = 0; i < n; i++){
            cnt[nums[i]]++;
            if(cnt[nums[i]] == 2)
                return nums[i];
        }
    }
};
