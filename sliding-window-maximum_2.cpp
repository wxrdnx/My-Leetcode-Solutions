class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> left_max(nums.size()), right_max(nums.size());
        vector<int> result;
        for (int i = 0, curr_max; i < nums.size(); i++) {
            if (i % k == 0) {
                curr_max = nums[i];
            } else if (nums[i] > curr_max) {
                curr_max = nums[i]; 
            }
            left_max[i] = curr_max;
        }
        for (int i = nums.size() - 1, curr_max; i >= 0; i--) {
            if (i == nums.size() - 1 || (i + 1) % k == 0) {
                curr_max = nums[i];
            } else if (nums[i] > curr_max) {
                curr_max = nums[i]; 
            }
            right_max[i] = curr_max;
        }
        for (int i = k - 1; i < nums.size(); i++) {
            result.push_back(max(left_max[i], right_max[i - k + 1]));
        }
        return result;
    }
};

// Time: O(n)
// Space: O(n)
