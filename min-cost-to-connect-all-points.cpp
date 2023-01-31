class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        /* Prim's Algorithm on complete graph */
        vector<int> dist(points.size(), numeric_limits<int>::max());
        int total = 0, u = 0;
        for (int i = 1; i < points.size(); i++) {
            dist[u] = -1;
            int min_dist = numeric_limits<int>::max(), min_node;
            for (int v = 0; v < points.size(); v++) {
                if (dist[v] != -1) {
                    int manhattan = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    dist[v] = min(dist[v], manhattan);
                    if (dist[v] < min_dist) {
                        min_dist = dist[v];
                        min_node = v;
                    }
                }
            }
            total += min_dist;
            u = min_node;
        }
        return total;
    }
};

// Time: O(n^2)
// Space: O(n)
