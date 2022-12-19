class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int i = 0, size = nums.size();
        while (i < size - 2) {
            int left = i + 1, right = size - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum > 0) {
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    do {
                        right--;
                    } while (right >= 0 && nums[right] == nums[right + 1]);
                    do {
                        left++;
                    } while (left < size && nums[left] == nums[left - 1]);
                }
            }
            do {
                i++;
            } while (i < size && nums[i] == nums[i - 1]);
        }
        return result;
    }
};

// Time: O(n^2)
// Space: O(1)
