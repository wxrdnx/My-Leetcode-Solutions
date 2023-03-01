class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result = {{}};
        for (int i = 0; i < nums.size(); i++) {
            int size = result.size();
            for (int j = 0; j < size; j++) {
                vector<int> element = result[j];
                element.push_back(nums[i]);
                result.push_back(move(element));
            }
        }
        return result;
    }
};

// Time: O(n * 2^n)
// Space: O(n * 2^n)

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(result, nums, {}, 0);
        return result;
    }
private:
    void backtrack(vector<vector<int>>& result, vector<int>& nums, vector<int>&& elements, int pos) {
        if (pos == nums.size()) {
            result.push_back(elements);
            return;
        }
        backtrack(result, nums, move(elements), pos + 1);
        elements.push_back(nums[pos]);
        backtrack(result, nums, move(elements), pos + 1);
        elements.pop_back();
    }
};

// Time: O(n * 2^n)
// Space: O(n)
