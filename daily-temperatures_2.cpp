class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size());
        for (int i = temperatures.size() - 1; i >= 0; i--) {
            int j = i + 1;
            while (j < temperatures.size() && temperatures[j] <= temperatures[i]) {
                j = result[j] == 0 ? temperatures.size() : j + result[j];
            }
            if (j < temperatures.size()) {
                result[i] = j - i;
            }
        }
        return result;
    }
};

// Time: O(n)
// Space: O(1)
