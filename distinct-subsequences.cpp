class Solution {
public:
    int numDistinct(string s, string t) {
        /*
         * dp[0][i] = 1
         * if s[i - 1] == t[j - 1]: dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1]
         * otherwise:               dp[i][j] = dp[i - 1][j]    
         */
        vector<unsigned long> dp(t.length() + 1);
        dp[0] = 1;
        for (int i = 1; i <= s.length(); i++) {
            for (int j = t.length(); j > 0; j--) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
            dp[0] = 1;
        }
        return dp[t.length()];
    }
};
