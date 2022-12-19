class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int num_max = *max_element(nums.begin(), nums.end());
        int num_bits = static_cast<int>(log2(num_max)) + 1;
        int dup = 0, size = nums.size();
        for (int i = 0; i < num_bits; i++) {
            int base_bit_count = 0, num_bit_count = 0;
            int mask = 1 << i;
            for (int j = 0; j < size; j++) {
                base_bit_count += !!(j & mask);
                num_bit_count += !!(nums[j] & mask);
            }
            /* If num_bit_count > base_bit_count, then this bit must be set */
            if (num_bit_count > base_bit_count) {
                dup |= mask;
            }
        }
        return dup;
    }
};

// Time: O(nlog(n))
// Space: O(1)
