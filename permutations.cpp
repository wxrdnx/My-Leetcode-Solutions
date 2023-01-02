class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
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
		for (auto i = now; i < nums.size(); i++) {
		    swap(nums[i], nums[now]);
		    backtrack(result, nums, now + 1);
		    swap(nums[i], nums[now]);
		}
    }
};

// Time: O(n!)
// Space: O(n)
