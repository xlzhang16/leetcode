class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> v;
        for(int i = 0 ; i< nums.size(); i++){
            int tmp = abs(nums[i]);
            if(nums[tmp - 1] > 0)
                nums[tmp - 1] = -nums[tmp - 1];
            else v.push_back(tmp);
        }
        return v;
    }
};
