class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long totalSum = 0;
        for (int num : nums) {
            totalSum = (totalSum + num) % p;
        }

        int rem = totalSum;
        if (rem == 0) return 0;

        unordered_map<int, int> mp;
        mp[0] = -1;
        long long cur = 0;
        int minLen = n;

        for (int i = 0; i < n; ++i) {
            cur = (cur + nums[i]) % p;
            int target = (cur - rem + p) % p;
            if (mp.count(target)) {
                minLen = min(minLen, i - mp[target]);
            }
            mp[cur] = i;
        }

        return minLen == n ? -1 : minLen;
    }
};
