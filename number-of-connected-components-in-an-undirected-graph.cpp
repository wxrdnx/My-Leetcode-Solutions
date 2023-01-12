class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n), rank(n);
        iota(parent.begin(), parent.end(), 0);
        int count = n;
        for (auto& edge : edges) {
            int xp = root(parent, edge[0]), yp = root(parent, edge[1]);
            if (xp != yp) {
                count--;
            } else if (rank[xp] < rank[yp]) {
                parent[xp] = yp;
            } else if (rank[yp] > rank[xp]) {
                parent[yp] = xp;
            } else {
                parent[yp] = xp;
                rank[xp]++;
            }
        }
        return count;
    }
private:
    int root(vector<int>& parent, int x) {
        if (parent[x] != x) {
            parent[x] = root(parent, parent[x]);
        }
        return parent[x];
    }
};
