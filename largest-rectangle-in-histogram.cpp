class Solution {
    using Pair = pair<int, int>;
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<Pair> stk;
        int left = 0, right = 0, max_area = 0;
        while (right < heights.size()) {
            left = right;
            while (!stk.empty() && heights[right] < stk.top().second) {
                left = stk.top().first;
                max_area = max(max_area, (right - left) * stk.top().second);
                stk.pop();
            }
            stk.push(make_pair(left, heights[right]));
            right++;
        }
        while (!stk.empty()) {
            left = stk.top().first;
            max_area = max(max_area, (right - left) * stk.top().second);
            stk.pop();
        }
        return max_area;
    }
};

// Time: O(n)
// Space: O(1)
