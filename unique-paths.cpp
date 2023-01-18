class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m < n) {
            return uniquePaths(n, m);
        }
        vector<int> dp(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};

// Time: O(m * n)
// Space: O(min(m, n))
