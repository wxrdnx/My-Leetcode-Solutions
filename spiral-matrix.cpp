class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> stops = {n, m - 1, n - 1, m - 2};
        vector<int> result;
        int row = 0, col = -1, dir = 0;
        while (stops[dir] > 0) {
            for (int i = 0; i < stops[dir]; i++) {
                row += dirs[dir][0];
                col += dirs[dir][1];
                result.push_back(matrix[row][col]);
            }
            stops[dir] -= 2;
            dir = (dir + 1) % 4;
        }
        return result;
    }
};
