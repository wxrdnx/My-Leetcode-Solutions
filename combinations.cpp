class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        backtrack(result, {}, n, k, 1);
        return result;
    }
private:
    void backtrack(vector<vector<int>>& result, vector<int> &&curr, int n, int k, int start) {
        if (k == 0) {
            result.push_back(curr);
            return;
        }
        for (int i = start; i <= n; i++) {
            curr.push_back(i);
            backtrack(result, move(curr), n, k - 1, i + 1);
            curr.pop_back();
        }
    }
};
