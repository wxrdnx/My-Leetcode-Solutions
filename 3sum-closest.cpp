class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int min_diff = numeric_limits<int>::max();
        int result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {  
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                int diff = abs(sum - target);
                if (diff == 0) {
                    return target;
                } else if (diff < min_diff) {
                    min_diff = diff;
                    result = sum;
                }
                if (sum > target) {
                    right--;
                } else {
                    left++;
                }
            }
        }
        return result;
    }
};

// Time: O(n^2)
// Space: O(log(n))
