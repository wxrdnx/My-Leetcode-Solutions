class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, min_price = numeric_limits<int>::max();
        for (auto& price : prices) {
            min_price = min(min_price, price);
            profit = max(profit, price - min_price);
        }
        return profit;
    }
};
