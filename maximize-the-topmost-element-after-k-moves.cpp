class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if (nums.size() == 1) {
            return (k % 2 == 0) ? nums[0] : -1;
        } else if (k <= 1) {
            return nums[k];
        } else if (k < nums.size()) {
            return max(nums[k], *max_element(nums.begin(), nums.begin() + k - 1));
        } else if (k == nums.size()) {
            return *max_element(nums.begin(), nums.end() - 1);
        } else {
            return *max_element(nums.begin(), nums.end());
        }
    }
};
