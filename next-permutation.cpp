class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int left = len - 2;
        while (left >= 0 && nums[left + 1] <= nums[left]) {
            left--;
        }
        if (left < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int right = left + 1;
        while (right < len && nums[right] > nums[left]) {
            right++;
        }
        swap(nums[left], nums[right - 1]);
        reverse(nums.begin() + left + 1, nums.end());
    }
};
