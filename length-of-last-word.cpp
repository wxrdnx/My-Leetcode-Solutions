class Solution {
public:
    int lengthOfLastWord(string s) {
        int result = 0, curr = s.length() - 1;
		while(curr >= 0 && s[curr] == ' ') {
			curr--;
		}
		while(curr >= 0 && s[curr] != ' ') {
			curr--;
			result++;
		}
		return result;
    }
};
