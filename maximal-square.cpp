class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<int> dp(matrix[0].size() + 1);
        int max_len = 0;
        /* 
         * matrix[i][j] == 0 -> dp[i][j] = 0
         * matrix[i][j] == 1 -> dp[i][j] = min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]) + 1
         */
        for (int i = 1; i <= matrix.size(); i++) {
            int prev = 0;
            for (int j = 1; j <= matrix[0].size(); j++) {
                int tmp = dp[j];
                if (matrix[i - 1][j - 1] == '0') {
                    dp[j] = 0;
                } else {
                    dp[j] = min({dp[j - 1], dp[j], prev}) + 1;
                    max_len = max(max_len, dp[j]);
                }
                prev = tmp;
            }
        }
        return max_len * max_len;
    }
};

// Time: O(m * n)
// Space: O(n)
