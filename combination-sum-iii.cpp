class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        backtrack(result, {}, k, 1, n);
        return result;
    }
private:
    void backtrack(vector<vector<int>>& result, vector<int>&& nums, int k, int now, int total) {
        if (k == 0) {
            if (total == 0) {
                result.push_back(nums);
            }
            return;
        }
        int threshold = min(total, 9);
        for (int i = now; i <= threshold; i++) {
            nums.push_back(i);
            backtrack(result, move(nums), k - 1, i + 1, total - i);
            nums.pop_back();
        }
    }
};
