class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<int> lens;
        unordered_set<string> words;
        for (auto& word : wordDict) {
            words.insert(word);
            lens.insert(word.length());
        }
        vector<bool> dp(s.length() + 1);
        dp[0] = true;
        for (int i = 1; i <= s.length(); i++) {
            for (int len : lens) {
                if (i >= len && dp[i - len] && words.find(s.substr(i - len, len)) != words.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
};

// Time: O(n ^ 3)
// Space: O(n)
