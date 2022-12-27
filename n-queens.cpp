class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<int> config(n);
        bf(n, 0, 0, 0, 0, config, result);
        return result;
    }
private:
    void bf(int n, int row, int &&ng_column, int &&ng_up_right, int &&ng_down_right, vector<int>& config, vector<vector<string>>& result) {
        if (row == n) {
            vector<string> board;
            string repr(n, '.');
            for (int row = 0; row < n; row++) {
                repr[config[row]] = 'Q';
                board.push_back(repr);
                repr[config[row]] = '.';
            }
            result.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            int col_bit = (1 << col);
            int up_right_bit = (1 << (row + col));
            int down_right_bit = (1 << (row - col + n - 1));
            if (!((ng_column & col_bit) || (ng_up_right & up_right_bit) || (ng_down_right & down_right_bit))) {
                config[row] = col;
                ng_column |= col_bit;
                ng_up_right |= up_right_bit;
                ng_down_right |= down_right_bit;
                bf(n, row + 1, move(ng_column), move(ng_up_right), move(ng_down_right), config, result);
                ng_column &= ~col_bit;
                ng_up_right &= ~up_right_bit;
                ng_down_right &= ~down_right_bit;
            }
        }
    }
};
