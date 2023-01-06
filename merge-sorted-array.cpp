class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while (m && n) {
            if (nums1[m - 1] < nums2[n - 1]) {
                n--;
                nums1[m + n] = nums2[n];
            } else {
                m--;
                nums1[m + n] = nums1[m];
            }
        }
        while (n--) {
            nums1[n] = nums2[n];
        }
    }
};

// Time: O(m + n)
// Space: O(1)
