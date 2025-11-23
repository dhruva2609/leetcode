class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp = {0, INT_MIN, INT_MIN};

        for (int num : nums) {
            vector<int> next_dp = dp;
            for (int i = 0; i < 3; ++i) {
                if (dp[i] != INT_MIN) {
                    int sum = dp[i] + num;
                    next_dp[sum % 3] = max(next_dp[sum % 3], sum);
                }
            }
            dp = next_dp;
        }

        return dp[0];
    }
};
