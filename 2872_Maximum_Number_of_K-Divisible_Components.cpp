class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int count = 0;
        function<long long(int, int)> dfs = [&](int node, int parent) {
            long long sum = values[node];
            for (int neighbor : adj[node]) {
                if (neighbor != parent) {
                    sum += dfs(neighbor, node);
                }
            }
            if (sum % k == 0) {
                count++;
                return 0LL;
            }
            return sum;
        };

        dfs(0, -1);
        return count;
    }
};
