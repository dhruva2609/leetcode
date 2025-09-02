class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                int Ax = points[i][0], Ay = points[i][1];
                int Bx = points[j][0], By = points[j][1];

                if (Ax <= Bx && Ay >= By) {
                    bool valid = true;
                    for (int k = 0; k < n; k++) {
                        if (k == i || k == j) continue;
                        int Px = points[k][0], Py = points[k][1];
                        if (min(Ax, Bx) <= Px && Px <= max(Ax, Bx) &&
                            min(Ay, By) <= Py && Py <= max(Ay, By)) {
                            valid = false;
                            break;
                        }
                    }
                    if (valid) ans++;
                }
            }
        }
        return ans;
    }
};
