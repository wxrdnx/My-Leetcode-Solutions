class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }
        vector<int> state(numCourses);
        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0 && !dfs(adj, state, i)) {
                return false;
            }
        }
        return true;
    }
private:
    bool dfs(vector<vector<int>>& adj, vector<int>& state, int curr) {
        state[curr] = 1;
        for (auto& next : adj[curr]) {
            if (state[next] == 1 || 
                    (state[next] == 0 && !dfs(adj, state, next))) {
                return false;
            }
        }
        state[curr] = 2;
        return true;
    }
};

// Time: O(V + E)
// Space: O(V + E)
