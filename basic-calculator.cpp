class Solution {
public:
    int calculate(string s) {
        vector<long> nums = {0}, signs;
        long num = 0, sign = 1;
        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                num = num * 10 + s[i] - '0';
            } else if (s[i] == '(') {
                signs.push_back(sign);
                nums.push_back(0);
                sign = 1;
                num = 0;
            } else if (s[i] != ' ') {
                nums.back() += sign * num;
                if (s[i] == ')') {
                    long prev = signs.back() * nums.back();
                    signs.pop_back();
                    nums.pop_back();
                    nums.back() += prev;
                }
                sign = (s[i] == '-' ? -1 : 1);
                num = 0;
            }
        }
        return nums[0] + sign * num;
    }
};
