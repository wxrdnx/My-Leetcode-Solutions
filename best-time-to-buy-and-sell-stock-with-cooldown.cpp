class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
         * buy[i] = max(buy[i - 1], cooldown[i - 1] - price[i])
         * sell[i] = buy[i - 1] + price[i]
         * cooldown[i] = mqx(cooldown[i - 1], sell[i - 1])
         */
        int buy = numeric_limits<int>::min(), sell = 0, cooldown = 0;
        for (auto& price : prices) {
            int sell_tmp = sell;
            sell = buy + price;
            buy = max(buy, cooldown - price);
            cooldown = max(cooldown, sell_tmp);
        }
        return max({buy, sell, cooldown});
    }
};

// Time: O(n)
// Space: O(1)
