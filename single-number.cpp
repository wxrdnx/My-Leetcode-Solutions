class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int answer = 0;
        for (auto& num : nums) {
            answer ^= num;
        }
        return answer;
    }
};

// Time: O(n)
// Space: O(1)
