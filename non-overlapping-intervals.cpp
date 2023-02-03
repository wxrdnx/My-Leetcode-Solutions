class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& interval1, auto& interval2) {
            return interval1[1] < interval2[1];
        });
        int count = 0, right = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < right) {
                count++;
            } else {
                right = intervals[i][1];
            }
        }
        return count;
    }
};

// Time: O(n * log(n))
// Space: O(log(n))
