class Solution {
private:
    int manual_gcd(int a, int b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

public:
    int minOperations(vector<int>& nums) {
        int N = nums.size();
        int ones_count = 0;

        int total_gcd = nums[0];

        for (int x : nums) {
            if (x == 1) {
                ones_count++;
            }
            total_gcd = manual_gcd(total_gcd, x);
        }

        if (total_gcd > 1) {
            return -1;
        }

        if (ones_count > 0) {
            return N - ones_count;
        }

        int min_len = N + 1;

        for (int i = 0; i < N; ++i) {
            int current_gcd = nums[i];

            for (int j = i + 1; j < N; ++j) {
                current_gcd = manual_gcd(current_gcd, nums[j]);

                if (current_gcd == 1) {
                    min_len = min(min_len, j - i + 1);
                    break;
                }
            }
        }

        return (min_len - 1) + (N - 1);
    }
};
