class Solution {
public:
    string longestPalindrome(string s) {
        string pad = "|";
        for (char& c : s) {
            pad.push_back(c);
            pad.push_back('|');
        }
        vector<int> count(pad.size());
        int max_len = 0, max_i = 0, center = 0, right = 0;
        for (int i = 0; i < pad.size(); i++) {
            if (i < right) {
                count[i] = min(count[center * 2 - i], right - i);
            }
            while (i - count[i] >= 0 && i + count[i] < pad.size() && pad[i - count[i]] == pad[i + count[i]]) {
                count[i]++;
            }
            if (i + count[i] > right) {
                center = i;
                right = i + count[i];
            }
            if (count[i] > max_len) {
                max_i = i;
                max_len = count[i] - 1;
            }
        }
        return s.substr(max_i / 2 - max_len / 2, max_len);
    }
};

// Time: O(n)
// Space: O(1)
