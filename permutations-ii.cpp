class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        backtrack(result, nums, 0);
        return result;
    }
private:
    void backtrack(vector<vector<int>>& result, vector<int>& nums, int now) {
        if (now == nums.size()) {
            result.push_back(nums);
            return;
        }
        for (int i = now; i < nums.size(); i++) {
            if (i == now || nums[i] != nums[now]) {
                swap(nums[i], nums[now]);
                backtrack(result, nums, now + 1);
            }
        }
        rotate(nums.begin() + now, nums.begin() + now + 1, nums.end());
    }
};

// Time: O(n!)
// Space: O(n)
