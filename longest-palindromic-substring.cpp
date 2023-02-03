class Solution {
public:
    string longestPalindrome(string s) {
        int max_len = 0, max_i = 0;
        for (int i = 0; i < s.length(); i++) {
            int len = max(expand(s, i, i), expand(s, i - 1, i));
            if (len > max_len) {
                max_len = len;
                max_i = i - (len / 2);
            }
        }
        return s.substr(max_i, max_len);
    }
private:
    int expand(string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
};

// Time: O(n ^ 2)
// Space: O(1)

class Solution {
public:
    string longestPalindrome(string s) {
        /* Manacher's Algorithm */
        string pad = "|";
        for (char& c : s) {
            pad.push_back(c);
            pad.push_back('|');
        }
        vector<int> count(pad.length());
        int max_len = 0, max_i = 0, center = 0, right = 0;
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
            if (count[i] > max_len) {
                max_i = i;
                max_len = count[i] - 1;
            }
        }
        return s.substr(max_i / 2 - max_len / 2, max_len);
    }
};

// Time: O(n)
// Space: O(n)
