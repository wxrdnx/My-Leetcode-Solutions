class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string &s) {
        vector<int> mapping(256);
        int left = 0, right = 0;
        int result = 0, count = 0;
        while (right < s.length()) {
            if (mapping[s[right]] == 0) {
                count++;
            }
            mapping[s[right]]++;
            if (count > 2) {
                result = max(result, right - left);
                while (count > 2) {
                    mapping[s[left]]--;
                    if (mapping[s[left]] == 0) {
                        count--;
                    }
                    left++;
                }
            }
            right++;
        }
        return max(result, right - left);
    }
};

// Time: O(n)
// Space: O(1)
