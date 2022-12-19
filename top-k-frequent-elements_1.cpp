class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> bucket(nums.size() + 1);
        unordered_map<int, int> m;
        vector<int> result;
        for (int num : nums) {
            m[num]++;
        }
        for (const auto &[num, count] : m) {
            bucket[count].push_back(num);
        }
        for (int i = nums.size(); i >= 0 && result.size() <= k; i--) {
            int size = bucket[i].size();
            if (size > 0) {
                result.insert(result.end(), bucket[i].begin(), bucket[i].end());
            }
        }
        return vector<int>(result.begin(), result.begin() + k);
    }
};

// Time: O(n)
// Space: O(n)
