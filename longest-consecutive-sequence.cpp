class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int longest = 0;
        for (auto& num : nums) {
            s.insert(num);
        }
        for (auto& num : s) {
            if (s.find(num - 1) == s.end()) {
                int curr = num, count = 1;
                while (s.find(curr + count) != s.end()) {
                    s.erase(curr + count);
                    count++;
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }
};

// Time: O(n)
// Space: O(n)
