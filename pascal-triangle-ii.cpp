class Solution {
public:
    vector<int> getRow(int rowIndex) {
        unsigned long prod = 1UL;
        vector<int> result(rowIndex + 1);
        result[0] = result[rowIndex] = 1;
        for (int numer = rowIndex, denom = 1; denom < rowIndex / 2 + 1; numer--, denom++) {
            prod = prod * numer / denom;
            result[numer - 1] = result[denom] = prod;
        }
        return result;
    }
};
