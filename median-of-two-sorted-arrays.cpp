class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total_len = nums1.size() + nums2.size();
        if (total_len % 2 == 1) {
            return findKthSmallest(nums1, nums2, total_len / 2);
        } else {
            return (findKthSmallest(nums1, nums2, (total_len - 1) / 2) + findKthSmallest(nums1, nums2, total_len / 2)) / 2;
        }
    }
private:
    double findKthSmallest(vector<int>& nums1, vector<int>& nums2, int k) {
        int left1 = 0, right1 = nums1.size() - 1;
        int left2 = 0, right2 = nums2.size() - 1;
        while (left1 <= right1 && left2 <= right2) {
            int len1 = (right1 - left1 + 1) / 2;
            int len2 = (right2 - left2 + 1) / 2;
            int mid1 = left1 + len1;
            int mid2 = left2 + len2;
            if (len1 + len2 < k) {
                if (nums1[mid1] < nums2[mid2]) {
                    left1 = mid1 + 1;
                    k -= len1 + 1;
                } else {
                    left2 = mid2 + 1;
                    k -= len2 + 1;
                }
            } else {
                if (nums1[mid1] > nums2[mid2]) {
                    right1 = mid1 - 1;
                } else {
                    right2 = mid2 - 1;
                }
            }
        }
        return left1 <= right1 ? nums1[left1 + k] : nums2[left2 + k];
    }
};

// Time: O(log(m + n))
// Space: O(1)
