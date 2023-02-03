class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int i = 0, size = nums.size();
        while (i < size - 3) {
            int j = i + 1;
            while (j < size - 2) {
                int left = j + 1, right = size - 1;
                while (left < right) {
                    long sum = static_cast<long>(nums[i]) + nums[j] + nums[left] + nums[right];
                    if (sum > target) {
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        result.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        do {
                            right--;
                        } while (right >= 0 && nums[right] == nums[right + 1]);
                        do {
                            left++;
                        } while (left < size && nums[left] == nums[left - 1]);
                    }
                }
                do {
                    j++;
                } while (j < size && nums[j] == nums[j - 1]);
            }
            do {
                i++;
            } while (i < size && nums[i] == nums[i - 1]);
        }
        return result;
    }
};

// Time: O(n^3)
// Space: O(log(n))
