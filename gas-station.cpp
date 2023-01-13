class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tank = 0, start = 0, deficit = 0;
        for (int i = 0; i < gas.size(); i++) {
            tank += gas[i] - cost[i];
            if (tank < 0) {
                deficit += tank;
                tank = 0;
                start = i + 1;
            }
        }
        return (tank + deficit >= 0) ? start : -1;
    }
};

// Time: O(n)
// Space: O(1)
