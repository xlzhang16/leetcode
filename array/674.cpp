class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int max_l = 1;
        int temp_l = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i - 1]){
                temp_l++;
                max_l = max(max_l, temp_l);
            }
            else temp_l = 1;
        }
        return max_l;
    }
};
