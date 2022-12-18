class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        permute_helper(result, nums, 0);
        return result;
    }
private:
    void permute_helper(vector<vector<int>> &result, vector<int> &nums, int now) {
		if (now == nums.size()) {
		    result.push_back(nums);
		    return;
		}
		for (auto i = now; i < nums.size(); i++) {
		    swap(nums[i], nums[now]);
		    permute_helper(result, nums, now + 1);
		    swap(nums[i], nums[now]);
		}
    }
};
