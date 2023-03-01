class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> digits(n);
        iota(digits.begin(), digits.end(), 1);
        string result;
        int n_fact = factorial(n);
        k--;
        for (int i = n; i > 0; i--) {
            n_fact /= i;
            auto it = digits.begin() + (k / n_fact);
            result.push_back(*it + '0');
            digits.erase(it);
            k %= n_fact;
        }
        return result;
    }
private:
    int factorial(int n) {
        return n == 0 ? 1 : n * factorial(n - 1);
    }
};

// Time: O(n ^ 2)
// Space: O(n)
