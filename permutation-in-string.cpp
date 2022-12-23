class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> mapping(256);
        for (char& c : s1) {
            mapping[c]++;
        }
        int count = s1.length();
        for (int i = 0; i < s2.length(); i++) {
            if (mapping[s2[i]] == 0) {
                count++;
            } else if (mapping[s2[i]] > 0) {
                count--;
            }
            mapping[s2[i]]--;
            if (i >= s1.length()) {
                mapping[s2[i - s1.length()]]++;
                if (mapping[s2[i - s1.length()]] == 0) {
                    count--;
                } else if (mapping[s2[i - s1.length()]] > 0) {
                    count++;
                }
            }
            if (count == 0) {
                return true;
            }
        }
        return false;
    }
};

// Time: O(n)
// Space: O(1)
