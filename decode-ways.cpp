class Solution {
public:
    int numDecodings(string s) {
        int dp0 = 0, dp1 = 1;
        for (int i = 0; i < s.size(); i++) {
            int sum = 0;
            if (s[i] != '0') {
                sum += dp1;
            }
            if (i > 0 && (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))) {
                sum += dp0;
            }
            dp0 = dp1;
            dp1 = sum;
        }
        return dp1;
    }
};

// Time: O(n)
// Space: O(1)
