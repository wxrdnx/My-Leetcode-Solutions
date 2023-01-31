class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        /* Bellman Ford's Algorithm */
        vector<int> dist(n, numeric_limits<int>::max());
        dist[src] = 0;
        for (int i = 0; i < k + 1; i++) {
            vector<int> prev(dist);
            for (auto& flight : flights) {
                int u = flight[0], v = flight[1], w = flight[2];
                if (prev[u] != numeric_limits<int>::max() && prev[u] + w < dist[v]) {
                    dist[v] = prev[u] + w;
                }
            }
        }
        return dist[dst] != numeric_limits<int>::max() ? dist[dst] : -1;
    }
};

// Time: O(k * E)
// Space: O(V)
