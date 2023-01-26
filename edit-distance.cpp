class Solution {
public:
    int minDistance(string word1, string word2) {
        /*
         * dp[i][0] = i
         * dp[0][j] = j
         * if (word1[i - 1] == word2[j - 1]): dp[i][j] = dp[i - 1][j - 1]
         * otherwise:                         dp[i][j] = min(insert, delete, edit)
         *                                             = min(dp[i][j - 1] + 1, dp[i - 1][j] + 1, dp[i - 1][j - 1] + 1)
         *                                             = min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]) + 1
         */
        vector<int> dp(word2.length() + 1);
        iota(dp.begin(), dp.end(), 0);
        for (int i = 1; i <= word1.size(); i++) {
            int diag = dp[0];
            dp[0] = i;
            for (int j = 1; j <= word2.size(); j++) {
                int tmp = dp[j];
                if (word1[i - 1] == word2[j - 1]) {
                    dp[j] = diag;
                } else {
                    dp[j] = min({dp[j - 1], dp[j], diag}) + 1;
                }
                diag = tmp;
            }
        }
        return dp[word2.length()];
    }
};
