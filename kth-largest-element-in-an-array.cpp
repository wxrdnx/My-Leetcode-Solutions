class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = partition(nums, left, right);
            int rlen = right - mid + 1;
            if (k < rlen) {
                left = mid + 1;
            } else if (k > rlen) {
                right = mid - 1;
                k -= rlen;
            } else {
                return nums[mid];
            }
        }
        return -1;
    }
private:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = left + rand() % (right - left + 1);
        swap(nums[pivot], nums[right]);
        int i = left, j = right - 1;
        while (i <= j) {
            if (nums[i] < nums[right]) {
                i++;
            } else {
                swap(nums[i], nums[j--]);
            }
        }
        swap(nums[i], nums[right]);
        return i;
    }
};

// Time: Θ(n), O(n^2)
// Space: O(1)
