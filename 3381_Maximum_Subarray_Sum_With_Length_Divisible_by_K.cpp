class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long ans = -2e18;
        long long currentSum = 0;
        vector<long long> minPrefix(k, 2e18);
        minPrefix[0] = 0;

        for (int i = 0; i < nums.size(); ++i) {
            currentSum += nums[i];
            int remainder = (i + 1) % k;

            if (minPrefix[remainder] != 2e18) {
                ans = max(ans, currentSum - minPrefix[remainder]);
            }

            minPrefix[remainder] = min(minPrefix[remainder], currentSum);
        }

        return ans;
    }
};
