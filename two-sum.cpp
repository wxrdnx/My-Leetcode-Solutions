class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> buff;
        for (int i = 0; i < nums.size(); i++) {
            if (buff.find(nums[i]) != buff.end()) {
                return {buff[nums[i]], i};
            }
            buff[target - nums[i]] = i;
        }
        return {};
    }
};

// Time: O(n)
// Space: O(n)
