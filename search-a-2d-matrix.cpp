class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int num = matrix[mid / n][mid % n];
            if (num < target) {
                left = mid + 1;
            } else if (num > target) {
                right = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};

// Time: O(log(mn))
// Space: O(1)
