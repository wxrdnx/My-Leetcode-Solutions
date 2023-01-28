class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size()));
        for (int d = 2; d < nums.size(); d++) {
            for (int i = 0; i + d < nums.size(); i++) {
                int j = i + d;
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = max(dp[i][j], nums[i] * nums[k] * nums[j] + dp[i][k] + dp[k][j]);
                }
            }
        }
        return dp[0][nums.size() - 1];
    }
};
