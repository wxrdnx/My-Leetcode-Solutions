class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        /*
         * dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i]
         */
        int step1 = 0, step2 = 0;
        for (int i = 0; i < cost.size(); i++) {
            int tmp = step2;
            step2 = min(step1, step2) + cost[i];
            step1 = tmp;
        }
        return min(step1, step2);
    }
};
