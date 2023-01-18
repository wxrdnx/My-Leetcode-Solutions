class Solution {
    constexpr static int INF = 100000;
    using Pair = pair<int, int>;
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<Pair>> adj(n + 1);
        for (auto& time : times) {
            adj[time[0]].emplace_back(time[1], time[2]);
        }
        vector<bool> visited(n + 1);
        vector<int> dist(n + 1, INF);
        priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
        int time = 0, count = n;
        dist[k] = 0;
        pq.emplace(0, k);
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            if (visited[u]) {
                continue;
            }
            count--;
            time = max(time, dist[u]);
            visited[u] = true;
            for (auto& next : adj[u]) {
                int v = next.first, w = next.second;
                if (!visited[v] && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }
        return count == 0 ? time : -1;
    }
};

// Time: O((V + E) * log(V))
// Space: O(V + E)
