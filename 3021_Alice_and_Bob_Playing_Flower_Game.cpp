class Solution {
public:
    long long flowerGame(int n, int m) {
        long long on = (n + 1LL) / 2; // odds in [1..n]
        long long en = n / 2;         // evens in [1..n]
        long long om = (m + 1LL) / 2; // odds in [1..m]
        long long em = m / 2;         // evens in [1..m]
        return on * em + en * om;
    }
};
