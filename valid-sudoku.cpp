class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9, vector<bool>(9, false));
        vector<vector<bool>> col(9, vector<bool>(9, false));
        vector<vector<bool>> box(9, vector<bool>(9, false));
        for (auto ri = 0; ri < 9; ri++) {
            for (auto ci = 0; ci < 9; ci++) {
                if (board[ri][ci] != '.') {
                    int bi = (ri / 3 * 3) + (ci / 3);
                    int num = board[ri][ci] - '0' - 1;
                    if (row[ri][num] || col[ci][num] || box[bi][num]) {
                        return false;
                    }
                    row[ri][num] = col[ci][num] = box[bi][num] = true;
                }
            }
        }
        return true;
    }
};
