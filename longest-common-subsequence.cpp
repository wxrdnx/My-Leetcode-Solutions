class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.length() < text2.length()) {
            return longestCommonSubsequence(text2, text1);
        }
        vector<int> dp(text2.length() + 1);
        /*
         * text1[i] == text2[j] -> dp[i][j] = dp[i - 1][j - 1] + 1
         * Otherwise            -> dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
         */
        for (int i = 1; i <= text1.length(); i++) {
            int prev = 0;
            for (int j = 1; j <= text2.length(); j++) {
                int tmp = dp[j];
                if (text1[i - 1] == text2[j - 1]) {
                    dp[j] = prev + 1;
                } else {
                    dp[j] = max(dp[j], dp[j - 1]);
                }
                prev = tmp;
            }
        }
        return dp[text2.length()];
    }
};

// Time: O(m * n)
// Space: O(min(m, n))
