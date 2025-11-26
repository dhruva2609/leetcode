class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int mod = 1e9 + 7;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, 0)));

        dp[0][0][grid[0][0] % k] = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int r = 0; r < k; ++r) {
                    if (dp[i][j][r] == 0) continue;

                    if (i + 1 < m) {
                        int next_r = (r + grid[i + 1][j]) % k;
                        dp[i + 1][j][next_r] = (dp[i + 1][j][next_r] + dp[i][j][r]) % mod;
                    }
                    if (j + 1 < n) {
                        int next_r = (r + grid[i][j + 1]) % k;
                        dp[i][j + 1][next_r] = (dp[i][j + 1][next_r] + dp[i][j][r]) % mod;
                    }
                }
            }
        }

        return dp[m - 1][n - 1][0];
    }
};
