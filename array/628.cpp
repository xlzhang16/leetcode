class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if(nums.size() == 3)
            return nums[0] * nums[1] * nums[2];
        sort(nums.begin(), nums.end());
        vector<int> pos, neg;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0)
                pos.push_back(nums[i]);
            else neg.push_back(nums[i]);
        }
        int n_p = pos.size(), n_n = neg.size();
        if(n_p == 0)
            return neg[n_n - 1] * neg[n_n - 2] * neg[n_n - 3];
        else{
            if(n_n <= 1)
                return pos[n_p - 1] * pos[n_p - 2] * pos[n_p - 3];
            else if(n_p <= 2)
                return pos[n_p - 1] * neg[0] * neg[1];
            else{
                return max(pos[n_p - 2] * pos[n_p - 3], neg[0] * neg[1]) * pos[n_p - 1];
            }
        }
    }
};
