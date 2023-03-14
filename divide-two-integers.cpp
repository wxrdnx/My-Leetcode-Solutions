class Solution {
public:
    int divide(int dividend, int divisor) {
        bool neg = (dividend > 0) ^ (divisor > 0);
        unsigned long dividend_l = labs(dividend), divisor_l = labs(divisor) << 32UL;
        unsigned long quotient = 0UL;
        for (int i = 0; i < 32; i++) {
            divisor_l >>= 1UL;
            quotient <<= 1UL;
            if (dividend_l >= divisor_l) {
                dividend_l -= divisor_l;
                quotient |= 1UL;
            }
        }
        /* Deal with overflow issues */
        if (!neg && static_cast<int>(quotient) < 0) {
            return numeric_limits<int>::max();
        }
        if (neg && static_cast<int>(-quotient) > 0) {
            return numeric_limits<int>::min();
        }
        return neg ? -quotient : quotient;
    }
};
