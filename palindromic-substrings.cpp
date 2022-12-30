class Solution {
public:
    int countSubstrings(string s) {
        /* Manacher's Algorithm */
        string pad = "|";
        for (char& c : s) {
            pad.push_back(c);
            pad.push_back('|');
        }
        vector<int> count(pad.length());
        int center = 0, right = 0, result = 0;
        for (int i = 0; i < pad.length(); i++) {
            if (i < right) {
                count[i] = min(count[center * 2 - i], right - i);
            }
            while (i >= count[i] && i + count[i] < pad.length() && pad[i - count[i]] == pad[i + count[i]]) {
                count[i]++;
            }
            if (i + count[i] >= right) {
                center = i;
                right = i + count[i];
            }
            result += count[i] / 2;
        }
        return result;
    }
};

// Time: O(n)
// Space: O(1)
