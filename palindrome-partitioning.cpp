class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length()));
        backtrack(result, dp, {}, s, 0);
        return result;
    }
private:
    void backtrack(vector<vector<string>>& result, vector<vector<bool>>& dp, vector<string>&& palindromes, string& s, int curr) {
        if (curr == s.length()) {
            result.push_back(palindromes);
            return;
        }
        for (int next = curr; next < s.length(); next++) {
            if (s[curr] == s[next] && (next - curr <= 1 || dp[curr + 1][next - 1])) {
                dp[curr][next] = true;
                palindromes.push_back(s.substr(curr, next - curr + 1));
                backtrack(result, dp, move(palindromes), s, next + 1);
                palindromes.pop_back();
            }
        }
    }
};

// Time: O(n * 2^n)
// Space: O(n^2)
