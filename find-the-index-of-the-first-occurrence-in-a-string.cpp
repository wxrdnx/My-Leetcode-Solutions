class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> lps(needle.length());
        build_lps(lps, needle);
        int i = 0, j = 0;
        while (i < haystack.length()) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            } else if (j == 0) {
                i++;
            } else {
                j = lps[j - 1];
            }
            if (j >= needle.length()) {
                return i - needle.length();
            }
        }
        return -1;
    }
private:
    void build_lps(vector<int> &lps, string &needle) {
        lps[0] = 0;
        int prev = 0, curr = 1;
        while (curr < needle.length()) {
            if (needle[curr] == needle[prev]) {
                lps[curr++] = ++prev;
            } else if (prev == 0) {
                lps[curr++] = 0;
            } else {
                prev = lps[prev - 1];
            }
        }
    }
};

// Time: O(m + n), m = len(haystack), n = len(needle)
// Space: O(n)
