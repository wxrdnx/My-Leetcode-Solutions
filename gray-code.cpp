class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> gray = {0};
        for (int i = 0; i < n; i++) {
            int size = gray.size();
            int mask = 1 << i;
            for (int j = size - 1; j >= 0; j--) {
                gray.push_back(gray[j] | mask);
            }
        }
        return gray;
    }
};

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        for (int i = 0; i < (1 << n); i++) {
            result.push_back(i ^ (i >> 1));
        }
        return result;
    }
};
