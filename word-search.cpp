class Solution {
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (dfs(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    bool dfs(vector<vector<char>>& board, string& word, int index, int row, int col) {
        if (index == word.length()) {
            return true;
        }
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[index]) {
            return false;
        }
        board[row][col] = '*';
        for (auto& dir : dirs) {
            if (dfs(board, word, index + 1, row + dir[0], col + dir[1])) {
                return true;
            }
        }
        board[row][col] = word[index];
        return false;
    }
};
