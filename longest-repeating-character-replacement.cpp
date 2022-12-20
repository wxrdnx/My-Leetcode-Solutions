class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26);
        int left = 0, right = 0;
        int result = 0, max_count = 0, curr_count = 0;
        while (right < s.length()) {
            curr_count = ++count[s[right] - 'A'];
            right++;
            max_count = max(max_count, curr_count);
            while (right - left - max_count > k) {
                curr_count = --count[s[left] - 'A'];
                left++;
                max_count = max(max_count, curr_count);
            }
            result = max(result, right - left);
        }
        return max(result, right - left);
    }
};

// Time: O(n)
// Space: O(1)
