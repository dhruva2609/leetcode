class Solution {
private:
    bool isNumericallyBalanced(int n) {
        if (n == 0) return false;

        map<int, int> counts;
        int temp = n;

        while (temp > 0) {
            int d = temp % 10;
            if (d == 0) return false;
            counts[d]++;
            temp /= 10;
        }

        for (auto const& [digit, count] : counts) {
            if (digit != count) {
                return false;
            }
        }

        return true;
    }

public:
    int nextBeautifulNumber(int n) {
        for (int i = n + 1; ; ++i) {
            if (isNumericallyBalanced(i)) {
                return i;
            }
        }
    }
};
