class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int size = matrix.size();
        for (int i = 0; i < size; i++) {
            vector<bool> row(size + 1), col(size + 1);
            for (int j = 0; j < size; j++) {
                if (row[matrix[i][j]] || col[matrix[j][i]]) {
                    return false;
                }
                row[matrix[i][j]] = col[matrix[j][i]] = true;
            }
        }
        return true;
    }
};
