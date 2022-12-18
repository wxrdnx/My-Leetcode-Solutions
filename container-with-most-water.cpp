class Solution {
public:
    int maxArea(vector<int>& height) {
        int water = 0;
        int left = 0, right = height.size() - 1;
        while (left < right) {
            int area;
            if (height[left] < height[right]) {
                area = (right - left) * height[left];
                left++;
            } else {
                area = (right - left) * height[right];
                right--;
            }
            water = max(water, area);
        }
        return water;
    }
};

// Time: O(n)
// Space: O(1)
