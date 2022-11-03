class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        unordered_map<long, long> seen;
        for (auto i = 0; i < nums.size(); i++) {
            if (i >= indexDiff + 1) {
                long prevShiftedNum = static_cast<long>(nums[i - indexDiff - 1]) - numeric_limits<int>::min();
                long prevBucketId = prevShiftedNum / (valueDiff + 1);
                seen.erase(prevBucketId);
            }
            long shiftedNum = static_cast<long>(nums[i]) - numeric_limits<int>::min();
            long bucketId = shiftedNum / (valueDiff + 1);
            if (seen.find(bucketId) != seen.end()
                    || (seen.find(bucketId - 1) != seen.end()
                        && shiftedNum - seen[bucketId - 1] <= valueDiff)
                    || (seen.find(bucketId + 1) != seen.end()
                        && seen[bucketId + 1] - shiftedNum <= valueDiff)) {
                return true;
            }
            seen[bucketId] = shiftedNum;
        }
        return false;
    }
};
