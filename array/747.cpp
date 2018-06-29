class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if(nums.size() == 1)
            return 0;
        int Max = -1, secondMax = -1;
        int k;
        for(int i = 0; i < nums.size(); i++){
            if(Max < nums[i]){
                secondMax = Max;
                Max = nums[i];
                k = i;
            }
            else if(nums[i] > secondMax)
                secondMax = nums[i];
        }
        return Max >= secondMax << 1 ? k : -1;
    }
};
