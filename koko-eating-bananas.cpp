class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left_k = 1, right_k = *max_element(piles.begin(), piles.end());
        while (left_k < right_k) {
            int mid_k = left_k + (right_k - left_k) / 2;
            int time = 0;
            for (auto& pile : piles) {
                time += (pile - 1) / mid_k + 1;
            }
            if (h < time) {
                left_k = mid_k + 1;
            } else {
                right_k = mid_k;
            }
        }
        return left_k;
    }
};

// Time: O(nlog(max(p)))
