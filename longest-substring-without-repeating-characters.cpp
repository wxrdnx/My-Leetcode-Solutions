class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> indices(256, -1);
        int longest = 0;
        int left = 0, right = 0;
        while (right < s.length()) {
            if (indices[s[right]] >= left) {
                longest = max(right - left, longest);
                left = indices[s[right]] + 1;
            }
            indices[s[right]] = right;
            right++;
        }
        return max(longest, right - left);
    }
};

// Time: O(n)
// Space: O(1)
