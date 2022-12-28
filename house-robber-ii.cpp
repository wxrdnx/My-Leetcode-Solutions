class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        return max(robHelper(nums, 0, nums.size() - 1), robHelper(nums, 1, nums.size()));
    }
private:
    int robHelper(vector<int>& nums, int start, int end) {
        int dp0 = 0, dp1 = 0;
        for (int i = start; i < end; i++) {
            int tmp = dp1;
            dp1 = max(dp0 + nums[i], dp1);
            dp0 = tmp;
        }
        return dp1;
    }
};

// Time: O(n)
// Space: O(1)
