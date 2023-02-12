class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int count = 0;
                for (int row = max(i - 1, 0); row <= min(i + 1, m - 1); row++) {
                    for (int col = max(j - 1, 0); col <= min(j + 1, n - 1); col++) {
                        if (row != i || col != j) {
                            count += (board[row][col] & 1);
                        }
                    }
                }
                if (count == 3 || ((board[i][j] & 1) && count == 2)) {
                    board[i][j] |= 2;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] >>= 1;
            }
        }
    }
};

// Time: O(m * n)
// Space: O(1)
