class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> mapping(256);
        for (auto& c : t) {
            mapping[c]++;
        }
        int count = t.length();
        int min_len = numeric_limits<int>::max(), min_i = 0;
        for (int left = 0, right = 0; right < s.length(); right++) {
            if (mapping[s[right]] > 0) {
                count--;
            }
            mapping[s[right]]--;
            while (count == 0) {
                if (mapping[s[left]] == 0) {
                    count++;
                    int len = right - left + 1;
                    if (len < min_len) {
                        min_len = len;
                        min_i = left;
                    }
                }
                mapping[s[left]]++;
                left++;
            }
        }
        return min_len != numeric_limits<int>::max() ? s.substr(min_i, min_len) : "";
    }
};
