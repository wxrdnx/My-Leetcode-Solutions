class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(256);
        int task_num = tasks.size();
        int max_count = 0, max_count_count = 0;
        for (char& c : tasks) {
            count[c]++;
            if (count[c] == max_count) {
                max_count_count++;
            } else if (count[c] > max_count) {
                max_count = count[c];
                max_count_count = 1;
            }
        }
        return max(task_num, (n + 1) * (max_count - 1) + max_count_count);
    }
};

// Time: O(n)
// Spaec: O(1)
