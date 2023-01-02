class Solution {
public:
    int minCut(string s) {
        vector<int> dp(s.length() + 1, s.length());
        dp[0] = -1;
        for (int i = 0; i < s.length(); i++) {
            for (int len = 0; i >= len && i + len < s.length() && s[i - len] == s[i + len]; len++) {
                dp[i + len + 1] = min(dp[i + len + 1], dp[i - len] + 1);
            }
            for (int len = 0; i >= len && i + len + 1 < s.length() && s[i - len] == s[i + len + 1]; len++) {
                dp[i + len + 2] = min(dp[i + len + 2], dp[i - len] + 1);
            }
        }
        return dp[s.length()];
    }
};

// Time: O(n^2)
// Space: O(n)
