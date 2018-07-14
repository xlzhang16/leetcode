class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int L = nums.size() - 2;
        for(; L >= 0; L--){
            if(nums[L] < nums[L + 1]){
                int k = L + 1;
                for(; k < nums.size(); k++){
                    if(nums[k] <= nums[L])
                        break;
                }
                int tmp = nums[L];
                nums[L] = nums[k - 1];
                nums[k - 1] = tmp;
                break;
            }
        }
        sort(nums.begin() + L + 1, nums.end());
    }
};
