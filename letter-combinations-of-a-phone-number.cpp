class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) {
            return {};
        }
        vector<string> mapping{"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;
        result.push_back("");
        for (auto& digit : digits) {
            vector<string> tmp;
            for (auto& prev : result) {
                for (auto& ch : mapping[digit - '0']) {
                    tmp.push_back(prev + ch);
                }
            }
            result = move(tmp);
        }
        return result;     
    }
};
