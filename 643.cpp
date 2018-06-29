class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int min_sum = 0;
        int tmp = 0;
        int i;
        for(i = 0; i < k; i++){
            tmp += nums[i]; 
        }
        min_sum = tmp;
        while(1){
            if(tmp > min_sum)
                min_sum = tmp;
            if(i >= nums.size())
                break;
            tmp -= nums[i - k];
            tmp += nums[i++];
        }
        return double(min_sum) / k;
    }
};
