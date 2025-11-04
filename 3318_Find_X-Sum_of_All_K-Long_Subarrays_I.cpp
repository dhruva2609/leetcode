class Solution {
private:
    int calculateXSum(const vector<int>& sub, int k, int x) {
        map<int, int> cnt;
        for (int v : sub) {
            cnt[v]++;
        }

        if (cnt.size() <= x) {
            int sum = 0;
            for (int v : sub) {
                sum += v;
            }
            return sum;
        }

        // Store as {frequency, value}
        vector<pair<int, int>> dat;
        for (auto const& [v, f] : cnt) {
            dat.push_back({f, v});
        }

        // Sort: Primary key (f) descending, Secondary key (v) descending
        sort(dat.begin(), dat.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first != b.first) {
                return a.first > b.first;
            }
            return a.second > b.second;
        });

        int x_sum = 0;

        for (int i = 0; i < x; ++i) {
            int f = dat[i].first;
            int v = dat[i].second;
            x_sum += v * f;
        }

        return x_sum;
    }

public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        int num_sub = n - k + 1;
        vector<int> ans(num_sub);

        for (int i = 0; i < num_sub; ++i) {
            vector<int> sub;
            for (int j = i; j < i + k; ++j) {
                sub.push_back(nums[j]);
            }

            ans[i] = calculateXSum(sub, k, x);
        }

        return ans;
    }
};
