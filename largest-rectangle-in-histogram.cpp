class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int result = 0;
        stack<int> stk;
        heights.push_back(-1);
        stk.push(-1);
        for (int i = 0; i < heights.size(); i++) {
            while (stk.top() != -1 && heights[i] < heights[stk.top()]) {
                int height = heights[stk.top()];
                stk.pop();
                result = max(result, (i - stk.top() - 1) * height);
            }
            stk.push(i);
        }
        return result;
    }
};

// Time: O(n)
// Space: O(n)
