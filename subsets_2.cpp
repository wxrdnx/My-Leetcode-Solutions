class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(result, nums, {}, 0);
        return result;
    }
private:
    void backtrack(vector<vector<int>>& result, vector<int>& nums, vector<int>&& elements, int curr) {
        if (curr == nums.size()) {
            result.push_back(elements);
            return;
        }
        backtrack(result, nums, move(elements), curr + 1);
        elements.push_back(nums[curr]);
        backtrack(result, nums, move(elements), curr + 1);
        elements.pop_back();
    }
};

// Time: O(n * 2^n)
// Space: O(n)
