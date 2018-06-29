class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool changed = false;
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] > nums[i + 1]){
                if(changed)
                    return false;
                if(i + 2 >= nums.size() || nums[i + 2] >= nums[i]){
                    nums[i + 1] = nums[i];
                    changed = true;
                }
                else if(i == 0 || nums[i - 1] <= nums[i + 1]){
                    nums[i] = nums[i + 1];
                    changed = true;
                }
                else return false;
            }
        }
        return true;
    }
};
