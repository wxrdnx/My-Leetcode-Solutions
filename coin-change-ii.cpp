class Solution {
public:
    int change(int amount, vector<int>& coins) {
        /*
         * dp[i][0] = 1
         * dp[i][j] = dp[i][j - coin] + dp[i - 1][j]
         */
        vector<int> dp(amount + 1);
        for (auto& coin : coins) {
            dp[0] = 1;
            for (int i = coin; i <= amount; i++) {
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};

// Time: O(m * n), m = number of coins, n = amount
// Space: O(n)
