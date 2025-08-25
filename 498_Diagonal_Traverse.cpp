class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if (mat.empty()) return {};

        int m = mat.size(), n = mat[0].size();
        vector<int> result;
        result.reserve(m * n);

        int r = 0, c = 0;
        for (int k = 0; k < m * n; k++) {
            result.push_back(mat[r][c]);
            if ((r + c) % 2 == 0) {
                if (c == n - 1) r++;
                else if (r == 0) c++;
                else { r--; c++; }
            } else {
                if (r == m - 1) c++;
                else if (c == 0) r++;
                else { r++; c--; }
            }
        }
        return result;
    }
};
