class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.length() < text2.length()) {
            return longestCommonSubsequence(text2, text1);
        }
        vector<int> dp(text2.length() + 1);
        for (int i = 1; i <= text1.length(); i++) {
            int pre = 0;
            for (int j = 1; j <= text2.length(); j++) {
                int tmp = dp[j];
                if (text1[i - 1] == text2[j - 1]) {
                    dp[j] = pre + 1;
                } else {
                    dp[j] = max(dp[j], dp[j - 1]);
                }
                pre = tmp;
            }
        }
        return dp[text2.length()];
    }
};

// Time: O(m * n)
// Space: O(min(m, n))
