class Solution {
public:
    string countAndSay(int n) {
        string result{"1"};
        while (--n) {
            string temp;
            int count = 1;
            for (int i = 1; i <= result.length(); i++) {
                if (result[i] == result[i - 1]) {
                    count++;
                } else {
                    temp += to_string(count) + result[i - 1];
                    count = 1;
                }
            }
            result = move(temp);
        }
        return result;
    }
};
