class Solution {
public:
    int jump(vector<int>& nums) {
        int threshold = 0, farthest = 0, count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > threshold) {
                threshold = farthest;
                count++;
            }
            farthest = max(i + nums[i], farthest);
        }
        return count;
    }
};
