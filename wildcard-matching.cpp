class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(2, vector<bool>(p.length() + 1, 0));
        dp[0][0] = true;
        for (int j = 1; j <= p.length() && p[j - 1] == '*'; j++) {
            dp[0][j] = true;
        }
        for (int i = 1; i <= s.length(); i++) {
            int curr = i & 1, prev = curr ^ 1;
            dp[curr][0] = false;
            for (int j = 1; j <= p.length(); j++) {
                if (p[j - 1] == '*') {
                    dp[curr][j] = dp[curr][j - 1] || dp[prev][j];
                } else {
                    dp[curr][j] = dp[prev][j - 1] && (p[j - 1] == '?' || s[i - 1] == p[j - 1]);
                }
            }
        }
        return dp[s.length() & 1][p.length()];
    }
};

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
