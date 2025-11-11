class Solution {
private:
    pair<int, int> count_zeros_and_ones(const string& s) {
        int zeros = 0;
        int ones = 0;
        for (char c : s) {
            if (c == '0') {
                zeros++;
            } else {
                ones++;
            }
        }
        return {zeros, ones};
    }

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        using namespace std;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (const string& s : strs) {
            pair<int, int> counts = count_zeros_and_ones(s);
            int zeros = counts.first;
            int ones = counts.second;

            for (int i = m; i >= zeros; --i) {
                for (int j = n; j >= ones; --j) {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - zeros][j - ones]);
                }
            }
        }

        return dp[m][n];
    }
};
