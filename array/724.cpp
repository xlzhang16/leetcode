class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return -1;

        int pre_sum[n] = {0};
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            pre_sum[i] = sum;
        }
        for(int i = 0; i < nums.size(); i++){
            int pos_sum = sum - pre_sum[i] + nums[i];
            if(pos_sum == pre_sum[i])
                return i;
        }
        return -1;
    }
};
