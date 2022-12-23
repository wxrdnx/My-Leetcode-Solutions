class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> left_max(nums.size()), right_max(nums.size());
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            left_max[i] = (i % k == 0 ? nums[i] : max(left_max[i - 1], nums[i]));
        }
        for (int i = nums.size() - 1, curr_max; i >= 0; i--) {
            right_max[i] = ((i == nums.size() - 1 || (i + 1) % k == 0) ? nums[i] : max(right_max[i + 1], nums[i]));
        }
        for (int i = k - 1; i < nums.size(); i++) {
            result.push_back(max(left_max[i], right_max[i - k + 1]));
        }
        return result;
    }
};

// Time: O(n)
// Space: O(n)
