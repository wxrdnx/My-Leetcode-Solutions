class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        int raccum = 1;
        for (auto i = 1; i < nums.size(); i++) {
            res[i] = res[i - 1] * nums[i - 1];
        }
        for (auto i = nums.size() - 1; i >= 1; i--) {
            raccum *= nums[i];
            res[i - 1] *= raccum;
        }
        return res;
    }
};
