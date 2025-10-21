class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        unordered_map<int,int> freq;
        int minL = INT_MAX, maxR = INT_MIN;
        for (int x : nums) {
            freq[x]++;
            minL = min(minL, x - k);
            maxR = max(maxR, x + k);
        }
        int offset = minL;
        int sz = maxR - minL + 3;
        vector<int> diff(sz, 0);
        for (int x : nums) {
            int L = x - k - offset;
            int R = x + k - offset;
            diff[L] += 1;
            diff[R + 1] -= 1;
        }
        int best = 0;
        int cur = 0;
        for (int i = 0; i <= maxR - minL + 1; ++i) {
            cur += diff[i];
            int v = i + offset;
            int existing = 0;
            auto it = freq.find(v);
            if (it != freq.end()) existing = it->second;
            int others = cur - existing;
            if (others < 0) others = 0;
            int addable = min((int)numOperations, others);
            best = max(best, existing + addable);
        }
        return best;
    }
};
