class Solution {
public:
    bool isPowerOfThree(int n) {

        const int maxPowerOfThree = 1162261467;
        return n > 0 && (maxPowerOfThree % n == 0);
    }
};
