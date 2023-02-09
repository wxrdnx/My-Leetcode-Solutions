class Solution {
public:
    bool isHappy(int n) {
        int fast = next(n), slow = n;
        while (fast != slow) {
            slow = next(slow);
            fast = next(next(fast));
        }
        return fast == 1;
    }
private:
    int next(int num) {
        int square_sum = 0;
        while (num) {
            square_sum += (num % 10) * (num % 10);
            num /= 10;
        }
        return square_sum;
    }
};

// Time: O(log(n))
// Space: O(1)
