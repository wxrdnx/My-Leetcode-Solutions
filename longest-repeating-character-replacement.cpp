class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> mapping(256);
        int left = 0, right = 0;
        int result = 0, max_len = 0;
        while (right < s.length()) {
            mapping[s[right]]++;
            max_len = max(max_len, mapping[s[right]]);
            if (right - left + 1 - max_len > k) {
                mapping[s[left]]--;
                left++;
            }
            result = max(result, right - left + 1);
            right++;
        }
        return result;
    }
};

// Time: O(n)
// Space: O(1)
