class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /* Kadane's Algorithm */
        int max_so_far = numeric_limits<int>::min(), curr_sum = 0;
        for (auto& num : nums) {
            curr_sum = max(num, curr_sum + num);
            max_so_far = max(max_so_far, curr_sum);
        }
        return max_so_far;
    }
};

// Time: O(n)
// Space: O(1)
