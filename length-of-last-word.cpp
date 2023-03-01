class Solution {
public:
    int lengthOfLastWord(string s) {
        int result = 0, pos = s.length() - 1;
		while(pos >= 0 && s[pos] == ' ') {
			pos--;
		}
		while(pos >= 0 && s[pos] != ' ') {
			pos--;
			result++;
		}
		return result;
    }
};
