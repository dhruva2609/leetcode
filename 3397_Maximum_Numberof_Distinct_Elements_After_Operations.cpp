class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long last = LLONG_MIN;
        int ans = 0;
        for (int x : nums) {
            long long low = x - k;
            long long high = x + k;
            long long val = max(last + 1, low);
            if (val <= high) {
                ans++;
                last = val;
            }
        }
        return ans;
    }
};
