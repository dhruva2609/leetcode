class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiag = -1;
        int maxArea = -1;

        for (auto &dim : dimensions) {
            int a = dim[0], b = dim[1];
            int diagSq = a * a + b * b;
            int area = a * b;

            if (diagSq > maxDiag) {
                maxDiag = diagSq;
                maxArea = area;
            } else if (diagSq == maxDiag && area > maxArea) {
                maxArea = area;
            }
        }

        return maxArea;
    }
};
