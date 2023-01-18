class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        auto range = equal_range(intervals.begin(), intervals.end(), newInterval, [](auto& interval1, auto &interval2) {
            return interval1[1] < interval2[0];
        });
        auto leftIt = range.first, rightIt = range.second;
        if (leftIt != rightIt) {
            newInterval[0] = min(newInterval[0], (*leftIt)[0]);
            newInterval[1] = max(newInterval[1], (*(rightIt - 1))[1]);
        }
        auto newIt = intervals.erase(leftIt, rightIt);
        intervals.insert(newIt, newInterval);
        return intervals;
    }
};

// Time: O(n)
// Space: O(1)
