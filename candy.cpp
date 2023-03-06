class Solution {
public:
    int candy(vector<int>& ratings) {
        int result = 1, upper, lower, i = 1;
        while (i < ratings.size()) {
            upper = lower = 1;
            while (i < ratings.size() && ratings[i - 1] < ratings[i]) {
                result += ++upper;
                i++;
            }
            while (i < ratings.size() && ratings[i - 1] > ratings[i]) {
                result += ++lower;
                i++;
            }
            while (i < ratings.size() && ratings[i - 1] == ratings[i]) {
                result++;
                i++;
            }
            result -= min(upper, lower) - 1;
        }
        return result;
    }
};

// Time: O(n)
// Space: O(1)
