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
