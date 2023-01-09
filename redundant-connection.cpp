class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> rank(1001), parent(1001);
        iota(parent.begin(), parent.end(), 0);
        for (auto& edge : edges) {
            int p1 = root(parent, edge[0]), p2 = root(parent, edge[1]);
            if (p1 == p2) {
                return edge;
            }
            if (rank[p1] < rank[p2]) {
                parent[p1] = p2;
            } else if (rank[p1] < rank[p2]) {
                parent[p2] = p1;
            } else {
                parent[p2] = p1;
                rank[p1]++;
            }
        }
        return {};
    }
private:
    int root(vector<int>& parent, int x) {
        if (x != parent[x]) {
            parent[x] = root(parent, parent[x]);
        }
        return parent[x];
    }
};
