class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        dfs(result, graph, {0}, 0);
        return result;
    }
private:
    void dfs(vector<vector<int>>& result, vector<vector<int>>& adj, vector<int>&& path, int curr) {
        if (curr == adj.size() - 1) {
            result.push_back(path);
            return;
        }
        for (auto& next : adj[curr]) {
            path.push_back(next);
            dfs(result, adj, move(path), next);
            path.pop_back();
        }
    }
};
