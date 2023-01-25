class Solution {
public:
    int myAtoi(string s) {
        if (s.length() == 0) {
            return 0;
        }
        int i = 0, sign = 1;
        long val = 0;
        while (i < s.length() && s[i] == ' ') {
			i++;
		}
        if (i == s.length()) {
            return 0;
        }
		if (s[i] == '+') {
			i++;
		} else if (s[i] == '-') {
            sign = -1;
            i++;
		}
        long upper_bound = numeric_limits<int>::max();
        long lower_bound = numeric_limits<int>::min();
        while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
            long tmp = val * 10 + sign * (s[i++] - '0');
            if (tmp > upper_bound) {
                return upper_bound;
            } else if (tmp < lower_bound) {
                return lower_bound;
            } else {
                val = tmp;
            }
        }
        return val;
    }
};
