class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_so_far = 1, min_so_far = 1, maximum = numeric_limits<int>::min();
        for (auto& num : nums) {
            if (num < 0) {
                swap(max_so_far, min_so_far);
            }
            maximum = max(maximum, max_so_far * num);
            max_so_far = max(max_so_far * num, 1);
            min_so_far = min(min_so_far * num, 1);
        }
        return maximum;
    }
};

// Time: O(n)
// Space: O(1)
