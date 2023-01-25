class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
		long reverse = 0;
        int tmp = x;
		while (tmp != 0) {
			reverse = reverse * 10 + tmp % 10;
			tmp /= 10;
		}
		return x == reverse;
    }
};
