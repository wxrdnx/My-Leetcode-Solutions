class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        vector<int> row;
        while (numRows--) {
            row.push_back(1);
            for (int i = row.size() - 2; i >= 1; i--) {
                row[i] += row[i - 1];
            }
            result.push_back(row);
        }
        return result;
    }
};
