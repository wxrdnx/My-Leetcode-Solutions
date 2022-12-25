class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> convert{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}}; 
        int result = convert[s.back()];
		for (int i = 0; i < s.length() - 1; i++) {
			if (convert[s[i]] < convert[s[i + 1]]) {
				result -= convert[s[i]];
			} else {
				result += convert[s[i]];
			}
		}
		return result;
    }
};
