class Solution {
public:
    vector<int> countBits(int n) {
        /* dp[0] = 0
         * if dp[i] is odd:  dp[i] = dp[i / 2] + 1
         * if dp[i] is even: dp[i] = dp[i / 2]
         */
        vector<int> result(n + 1);
        for (int i = 0; i <= n; i++) {
            result[i] = result[i >> 1] + (i & 1);
        }
        return result;
    }
};
