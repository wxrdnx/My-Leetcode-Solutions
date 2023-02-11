class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> heights(matrix[0].size() + 1);
        int result = 0;
        for (int i = 0; i < matrix.size(); i++) {
            stack<int> stk;
            stk.push(-1);
            for (int j = 0; j < heights.size(); j++) {
                if (j < matrix[0].size() && matrix[i][j] == '1') {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
                while (stk.top() != -1 && heights[j] < heights[stk.top()]) {
                    int height = heights[stk.top()];
                    stk.pop();
                    result = max(result, (j - stk.top() - 1) * height);
                }
                stk.push(j);
            }
        }
        return result;
    }
};

// Time: O(n)
// Space: O(n)
