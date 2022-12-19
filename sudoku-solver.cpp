class Solution {
    array<array<bool, 9>, 9> row{}, col{}, box{};
public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int ri = 0; ri < 9; ri++) {
            for (int ci = 0; ci < 9; ci++) {
                if (board[ri][ci] != '.') {
                    int num = board[ri][ci] - '0' - 1;
                    int bi = (ri / 3 * 3) + (ci / 3);
                    row[ri][num] = col[ci][num] = box[bi][num] = true;
                } 
            }
        }
        solver(board, 0);
    }
private:
    bool solver(vector<vector<char>>& board, int index) {
        if (index == 9 * 9) {
            return true;
        }
        int ri = index / 9, ci = index % 9, bi = (ri / 3 * 3) + (ci / 3);
        if (board[ri][ci] != '.') {
            return solver(board, index + 1);
        }
        for (int num = 0; num < 9; num++) {
            if (!row[ri][num] && !col[ci][num] && !box[bi][num]) {
                row[ri][num] = col[ci][num] = box[bi][num] = true;
                board[ri][ci] = num + '0' + 1;
                if (solver(board, index + 1)) {
                    return true;
                }
                row[ri][num] = col[ci][num] = box[bi][num] = false;
                board[ri][ci] = '.';
            }
        }  
        return false;
    }
};
