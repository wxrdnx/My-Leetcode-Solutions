class Solution {
public:
    bool isMatch(string s, string p) {
        vector<bool> dp(p.length() + 1);
        dp[0] = true;
        for (int j = 1; j <= p.length() && p[j - 1] == '*'; j++) {
            dp[j] = true;
        }
        for (int i = 1; i <= s.length(); i++) {
            int prev = dp[0];
            dp[0] = false;
            for (int j = 1; j <= p.length(); j++) {
                int tmp = dp[j];
                if (p[j - 1] == '*') {
                    dp[j] = dp[j - 1] || dp[j];
                } else {
                    dp[j] = prev && (p[j - 1] == '?' || s[i - 1] == p[j - 1]);
                }
                prev = tmp;
            }
        }
        return dp[p.length()];
    }
};

// Time: O(mn)
// Space: O(n)

class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0, asterisk = -1, match = -1;
        while (i <= s.length()) {
            if (p[j] == '?' || s[i] == p[j]) {
                i++;
                j++;
            } else if (p[j] == '*') {
                match = i;
                asterisk = j++;
            } else if (asterisk != -1) {
                i = match + 1;
                j = asterisk;
            } else {
                return false;
            }
        }
        while (j <= p.length() && p[j] == '*') {
            j++;
        }
        return j > p.length();
    }
};

// Time: O(mn)
// Space: O(1)
