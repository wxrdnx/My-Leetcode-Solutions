class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result = {{}};
        for (int i = 0; i < nums.size(); i++) {
            int count = 1, size = result.size();
            while (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
                count++;
                i++;
            }
            for (int j = 0; j < size; j++) {
                for (int k = 1; k <= count; k++) {
                    vector<int> elements = result[j];
                    elements.insert(elements.end(), k, nums[i]);
                    result.push_back(move(elements));
                }
            }
        }
        return result;
    }
};

// Time: O(n * 2^n)
// Space: O(n * 2^n)
