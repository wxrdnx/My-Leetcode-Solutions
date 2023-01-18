class Solution {
public:
    bool isMatch(string s, string p) {;
        vector<bool> dp(p.length() + 1);
        dp[0] = true;
        for (int i = 1; i <= p.length(); i++) {
            dp[i] = (p[i - 1] == '*' && dp[i - 2]);
        }
        for (int i = 1; i <= s.length(); i++) {
            int prev = dp[0];
            dp[0] = false;
            for (int j = 1; j <= p.length(); j++) {
                int tmp = dp[j];
                if (p[j - 1] == '*') {
                    dp[j] = dp[j - 2] || ((s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[j]);
                } else {
                    dp[j] = (s[i - 1] == p[j - 1] || p[j - 1] == '.') && prev;
                }
                prev = tmp;
            }
        }
        return dp[p.length()];
    }
};

// Time: O(m * n)
// Space: O(n)
