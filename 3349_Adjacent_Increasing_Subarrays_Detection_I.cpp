class Solution {
public:

    bool isStrictlyIncreasing(const vector<int>& nums, int start, int k) {
        for (int i = start; i < start + k - 1; ++i) {
            if (nums[i] >= nums[i+1]) {
                return false;
            }
        }
        return true;
    }

    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        for (int i = 0; i <= n - 2 * k; ++i) {
            bool first_subarray_ok = isStrictlyIncreasing(nums, i, k);

            if (first_subarray_ok) {
                bool second_subarray_ok = isStrictlyIncreasing(nums, i + k, k);

                                if (second_subarray_ok) {
                    return true;
                }
            }
        }

        return false;
    }
};-
