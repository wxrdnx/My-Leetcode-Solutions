class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> mapping(256);
        for (char& c : p) {
            mapping[c]++;
        }
        vector<int> result;
        int count = p.length();
        for (int i = 0; i < s.length(); i++) {
            if (mapping[s[i]] == 0) {
                count++;
            } else if (mapping[s[i]] > 0) {
                count--;
            }
            mapping[s[i]]--;
            if (i >= p.length()) {
                mapping[s[i - p.length()]]++;
                if (mapping[s[i - p.length()]] == 0) {
                    count--;
                } else if (mapping[s[i - p.length()]] > 0) {
                    count++;
                }
            }
            if (count == 0) {
                result.push_back(i - p.length() + 1);
            }
        }
        return result;
    }
};

// Time: O(n)
// Space: O(1)
