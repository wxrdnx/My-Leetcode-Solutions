class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string result;
        int delta = (numRows - 1) * 2;
        for (int row = 0; row < numRows; row++) {
            if (row == 0 || row == numRows - 1) {
                for (int i = row; i < s.size(); i += delta) {
                    result.push_back(s[i]);
                }
            } else {
                for (int i = row, j = i + (numRows - row - 1) * 2; i < s.length(); i += delta, j += delta) {
                    result.push_back(s[i]);
                    if (j < s.length()) {
                        result.push_back(s[j]);
                    }
                }
            }
        }
        return result;
    }
};
