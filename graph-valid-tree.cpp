class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> parent(n), rank(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        int count = n;
        for (auto& edge : edges) {
            int xp = root(parent, edge[0]), yp = root(parent, edge[1]);
            if (xp == yp) {
                return false;
            } else {
                count--;
                if (rank[xp] < rank[yp]) {
                    parent[xp] = yp;
                } else if (rank[xp] > rank[yp]) {
                    parent[yp] = xp;
                } else {
                    parent[yp] = xp;
                    rank[xp]++;
                }
            }
        }
        return count == 1;
    }
private:
    int root(vector<int>& parent, int x) {
        if (x != parent[x]) {
            parent[x] = root(parent, parent[x]);
        }
        return parent[x];
    }
};
