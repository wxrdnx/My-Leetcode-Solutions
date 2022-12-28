class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> result;
        backtrack(result, s, 0);
        return result;
    }
private:
    void backtrack(vector<string>& result, string& s, int i) {
        if (i == s.length()) {
            result.push_back(s);
            return;
        }
        backtrack(result, s, i + 1);
        if (isalpha(s[i])) {
            s[i] ^= (1 << 5);
            backtrack(result, s, i + 1);
        }
    }
};

// Time: O(n * 2^n)
// Space: O(n)
