class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& interval1, auto& interval2) {
            return interval1[0] < interval2[0];
        });
        vector<vector<int>> result = {intervals[0]};
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] > result.back()[1]) {
                result.push_back(intervals[i]);
            } else if (intervals[i][1] > result.back()[1]) {
                result.back()[1] = intervals[i][1];
            }
        }
        return result;
    }
};

// Time: O(n * log(n))
// Space: O(log(n))
