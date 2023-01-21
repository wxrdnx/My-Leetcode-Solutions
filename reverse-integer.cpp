class Solution {
public:
    int reverse(int x) {
		long result = 0;
		while (x != 0) {
			long tmp = result * 10 + x % 10;
			if (tmp > numeric_limits<int>::max() || tmp < numeric_limits<int>::min()) {
                return 0;
            }
            x /= 10;
			result = tmp;
		}
		return result;
    }
};
