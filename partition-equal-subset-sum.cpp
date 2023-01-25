class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        bitset<20001> dp;
        dp |= 1;
        for (int num : nums) {
            sum += num;
            dp |= (dp << num);
        }
        return sum % 2 == 0 && dp.test(sum / 2);
    }
};
