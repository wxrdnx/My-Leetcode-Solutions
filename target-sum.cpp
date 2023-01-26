class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        /*
         *     sum(+) + sum(neg) = target
         * +)  sum(+) - sum(neg) = sum(nums)
         * _________________________________
         *     sum(+) * 2        = target + sum(nums)
         *     sum(+)            = (target + sum(nums)) / 2
         */
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum + target < 0 || (sum + target) % 2 == 1) {
            return 0;
        }
        target = (sum + target) / 2;
        /* partition equal subset sum */
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (int num : nums) {
            for (int i = target; i >= num; i--) {
                dp[i] += dp[i - num];
            }
        }
        return dp[target];
    }
};
