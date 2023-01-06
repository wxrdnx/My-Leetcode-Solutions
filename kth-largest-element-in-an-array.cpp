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

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKthSmallest(nums, 0, nums.size() - 1, nums.size() - k);
    }
private:
    int findKthSmallest(vector<int>& nums, int left, int right, int k) {
        if (right - left < 5) {
            sort(nums.begin() + left, nums.begin() + right + 1);
            return nums[left + k];
        }
        vector<int> medians;
        for (int i = left; i <= right; i += 5) {
            int j = min(i + 5, right + 1);
            sort(nums.begin() + i, nums.begin() + j);
            medians.push_back(nums[(i + j) / 2]);
        }
        int median_of_median = findKthSmallest(medians, 0, medians.size() - 1, medians.size() / 2);
        int pivot = partition(nums, left, right, median_of_median);
        int llen = pivot - left;
        if (k < llen) {
            return findKthSmallest(nums, left, pivot - 1, k);
        } else if (k > llen) {
            return findKthSmallest(nums, pivot + 1, right, k - llen - 1);
        } else {
            return nums[pivot];
        }
    }
    int partition(vector<int>& nums, int left, int right, int target) {
        int pivot = find(nums.begin() + left, nums.begin() + right + 1, target) - nums.begin();
        int i = left, j = right - 1;
        swap(nums[pivot], nums[right]);
        while (i <= j) {
            if (nums[i] < target) {
                i++;    
            } else {
                swap(nums[i], nums[j--]);
            }
        }
        swap(nums[i], nums[right]);
        return i;
    }
};

// Time: O(n)
// Space: O(log(n))
