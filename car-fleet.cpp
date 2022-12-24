class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int, double> times;
        for (int i = 0; i < position.size(); i++) {
            times[position[i]] = static_cast<double>(target - position[i]) / speed[i];
        }
        int fleet = 0;
        double curr = -1;
        for (auto it = times.rbegin(); it != times.rend(); it++) {
            if (curr < it->second) {
                fleet++;
                curr = it->second;
            }
        }
        return fleet;
    }
};

// Time: O(nlog(n))
