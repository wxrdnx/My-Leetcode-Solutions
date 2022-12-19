class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        vector<int> wc(256);
        for (auto c : s) {
            wc[c]++;
        }
        for (auto c : t) {
            if (wc[c] == 0) {
                return false;
            }
            wc[c]--;
        }
        return true;
    }
};
