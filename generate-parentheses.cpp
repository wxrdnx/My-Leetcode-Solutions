class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateParenthesisHelper(n, 0, 0, move(""), result);
        return result;
    }
private:
    void generateParenthesisHelper(int n, int left, int right, string&& str, vector<string>& result) {
        if (left >= n) {
            int remain = 2 * n - left - right;
            for (int i = 0; i < remain; i++) {
                str.push_back(')');
            }
            result.push_back(str);
            for (int i = 0; i < remain; i++) {
                str.pop_back();
            }
            return;
        }
        if (left - right < n) {
            str.push_back('(');
            generateParenthesisHelper(n, left + 1, right, move(str), result);
            str.pop_back();
        }
        if (left > right) {
            str.push_back(')');
            generateParenthesisHelper(n, left, right + 1, move(str), result);
            str.pop_back();
        }
    }
};
