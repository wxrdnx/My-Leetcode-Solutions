class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1, length = nums.size();
        for (int i = 1; i < length; i++) {
            if (nums[i] != nums[i - 1]) {
                nums[count++] = nums[i];
            }
        }
        return count;
    }
}

// Time: O(n)
// Space: O(1)
