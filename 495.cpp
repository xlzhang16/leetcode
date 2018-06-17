class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_l = 0;
        int t_l = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                t_l++;
                if(max_l < t_l)
                    max_l = t_l;
            }
            else t_l = 0;
        }
        max_l = max(max_l, t_l);
        return max_l;
    }
};
