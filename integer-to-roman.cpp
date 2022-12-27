class Solution {
public:
    string intToRoman(int num) {
        vector<string> romans{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
		vector<int> digits{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
		string result{};
		for (int i = 0; i < romans.size(); i++) {
			while (num >= digits[i]) {
				result += romans[i];
				num -= digits[i];
			}
		}
		return result;
    }
};
