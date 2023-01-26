class Solution {
public:
    int rob(vector<int>& nums) {
        /*
         * dp[i] = max(dp[i - 1], dp[i - 2] + num)
         */
        int dp0 = 0, dp1 = 0;
        for (int& num : nums) {
            int tmp = dp1;
            dp1 = max(dp0 + num, dp1);
            dp0 = tmp;
        }
        return dp1;
    }
};
