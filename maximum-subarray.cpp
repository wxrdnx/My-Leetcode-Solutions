class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /* Kadane's Algorithm */
        int max_sum = numeric_limits<int>::min(), curr_sum = 0;
        for (auto& num : nums) {
            curr_sum = max(num, curr_sum + num);
            max_sum = max(max_sum, curr_sum);
        }
        return max_sum;
    }
};

// Time: O(n)
// Space: O(1)
