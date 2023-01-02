class Solution {
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, m, n, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    bool dfs(vector<vector<char>>& board, string& word, int m, int n, int index, int row, int col) {
        if (index == word.length()) {
            return true;
        }
        if (row < 0 || row >= m || col < 0 || col >= n || board[row][col] != word[index]) {
            return false;
        }
        board[row][col] = '*';
        for (auto& dir : dirs) {
            if (dfs(board, word, m, n, index + 1, row + dir[0], col + dir[1])) {
                return true;
            }
        }
        board[row][col] = word[index];
        return false;
    }
};
