class Solution {
public:
    int numSub(string s) {
        long long total_count = 0;
        long long current_length = 0;
        const int MOD = 1e9 + 7;

        for (char c : s) {
            if (c == '1') {
                current_length++;
            } else {
                long long contribution = current_length * (current_length + 1) / 2;
                total_count = (total_count + contribution) % MOD;
                current_length = 0;
            }
        }

        if (current_length > 0) {
            long long contribution = current_length * (current_length + 1) / 2;
            total_count = (total_count + contribution) % MOD;
        }

        return (int)total_count;
    }
};
