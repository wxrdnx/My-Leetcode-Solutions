class Solution {
    using PQ = priority_queue<string, vector<string>, greater<string>>;
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, PQ> adj;
        for (auto& ticket : tickets) {
            adj[ticket[0]].push(ticket[1]);
        }
        vector<string> result;
        dfs(adj, result, "JFK");
        reverse(result.begin(), result.end());
        return result;
    }
private:
    void dfs(unordered_map<string, PQ>& adj, vector<string>& result, const string& curr) {
        while (adj[curr].size() > 0) {
            const string next = adj[curr].top();
            adj[curr].pop();
            dfs(adj, result, next);
        }
        result.push_back(curr);
    }
};
