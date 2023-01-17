class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int max_len = 0;
        /* 
         * matrix[i][j] == 0 -> dp[i][j] = 0
         * matrix[i][j] == 1 -> dp[i][j] = min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]) + 1
         */
        vector<vector<int>> dp(2, vector<int>(n + 1));
        for (int i = 1; i <= m; i++) {
            int p = i & 1, q = p ^ 1;
            for (int j = 1; j <= n; j++) {
                if (matrix[i - 1][j - 1] == '0') {
                    dp[p][j] = 0;
                } else {
                    dp[p][j] = min({dp[p][j - 1], dp[q][j], dp[q][j - 1]}) + 1;
                    max_len = max(max_len, dp[p][j]);
                }
            }
        }
        return max_len * max_len;
    }
};

// Time: O(mn)
// Space: O(n)
