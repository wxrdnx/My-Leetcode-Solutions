class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> seq;
        for (auto& num : nums) {
            auto it = lower_bound(seq.begin(), seq.end(), num);
            if (it == seq.end()) {
                seq.push_back(num);
            } else {
                *it = num;
            }
        }
        return seq.size();
    }
};

// Time: O(n * log(n))
// Space: O(n)

class Solution {
    constexpr static int NORM = 10001, NORM_MAX = 20001;
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> bit(NORM_MAX + 1);
        for (auto& num : nums) {
            int norm = NORM + num;
            int max_len = get(bit, norm - 1);
            update(bit, norm, max_len + 1);
        }
        return get(bit, NORM_MAX);
    }
private:
    int get(vector<int>& bit, int index) {
        int result = 0;
        while (index > 0) {
            result = max(result, bit[index]);
            index -= index & -index;
        }
        return result;
    }
    void update(vector<int>& bit, int index, int value) {
        while (index < bit.size()) {
            bit[index] = max(bit[index], value);
            index += index & -index;
        }
    }
};

// Time: O(n * log(max(num)))
// Space: O(max(num))
