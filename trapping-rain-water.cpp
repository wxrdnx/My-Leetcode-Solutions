class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0;
        int left = 0, right = height.size() - 1;
        int left_max = -1, right_max = -1;
        while (left <= right) {
            if (left_max <= right_max) {
                left_max = max(left_max, height[left]);
                water += left_max - height[left];
                left++;
            } else {
                right_max = max(right_max, height[right]);
                water += right_max - height[right];
                right--;
            }
        }
        return water;
    }
};

// Time: O(n)
// Space: O(1)
