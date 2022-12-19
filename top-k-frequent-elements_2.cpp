class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        using Pair = pair<int, int>;
        unordered_map<int, int> freq;
        priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
        vector<int> result;
        for (auto &num : nums) {
            freq[num]++;
        }
        // Maintain a min-heap with size k
        for (auto &[num, count] : freq) {
            pq.push(make_pair(count, num));
            if (pq.size() > k) {
                pq.pop();
            }
        }
        while (k--) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};

// Time: O(nlog(k))
// Space: O(n)
