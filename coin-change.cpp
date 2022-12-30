class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> count(amount + 1, amount + 1);
        count[0] = 0;
        for (int i = 0; i <= amount; i++) {
            for (int& coin : coins) {
                if (i <= amount - coin) {
                    count[i + coin] = min(count[i + coin], count[i] + 1);
                }
            }
        }
        return count[amount] != amount + 1 ? count[amount] : -1;
    }
};

// Time: O(amount)
// Space: O(amount)

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> count(amount + 1, amount + 1);
        count[0] = 0;
        for (int& coin : coins) {
            for (int i = coin; i <= amount; i++) {
                if (count[i - coin] < count[i] - 1) {
                    count[i] = count[i - coin] + 1;
                }
            }
        }
        return count[amount] != amount + 1 ? count[amount] : -1;
    }
};

// Time: O(amount)
// Space: O(amount)
