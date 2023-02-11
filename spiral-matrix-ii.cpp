class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> square(n, vector<int>(n));
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> stops = {n, n - 1, n - 1, n - 2};
        int row = 0, col = -1, dir = 0, count = 0;
        while (stops[dir] > 0) {
            for (int i = 0; i < stops[dir]; i++) {
                row += dirs[dir][0];
                col += dirs[dir][1];
                square[row][col] = ++count;
            }
            stops[dir] -= 2;
            dir = (dir + 1) % 4;
        }
        return square;
    }
};
