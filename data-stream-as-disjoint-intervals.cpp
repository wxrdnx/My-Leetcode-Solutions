class SummaryRanges {
    vector<vector<int>> intervals;
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        vector<int> new_interval{value, value};
        auto range = equal_range(intervals.begin(), intervals.end(), new_interval, [](auto& interval1, auto& interval2) {
            return interval1[1] + 1 < interval2[0];
        });
        auto left_it = range.first, right_it = range.second;
        if (left_it != right_it) {
            new_interval[0] = min(new_interval[0], (*left_it)[0]);
            new_interval[1] = max(new_interval[1], (*(right_it - 1))[1]);
        }
        auto new_it = intervals.erase(left_it, right_it);
        intervals.insert(new_it, new_interval);
    }
    
    vector<vector<int>> getIntervals() {
        return intervals;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
