class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        backtrack(result, candidates, {}, 0, target);
        return result;
    }
private:
    void backtrack(vector<vector<int>>& result, vector<int>& candidates, vector<int>&& nums, int curr, int total) {
        if (total == 0) {
            result.push_back(nums);
            return;
        }
        for (int i = curr; i < candidates.size() && candidates[i] <= total; i++) {
            if (i == curr || candidates[i] != candidates[i - 1]) {
                nums.push_back(candidates[i]);
                backtrack(result, candidates, move(nums), i + 1, total - candidates[i]);
                nums.pop_back();
            }
        }
    }
};
