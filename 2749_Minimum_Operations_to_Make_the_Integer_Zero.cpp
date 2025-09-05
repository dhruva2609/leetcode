class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (long long k = 1; k <= 60; k++) {
            long long S = (long long)num1 - k * (long long)num2;
            if (S < 0) continue;
            if (__builtin_popcountll(S) <= k && k <= S) {
                return (int)k;
            }
        }
        return -1;
    }
};
