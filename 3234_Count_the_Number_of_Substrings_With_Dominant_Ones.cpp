class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + (s[i] == '1');
        vector<int> zeros;
        for (int i = 0; i < n; ++i) if (s[i] == '0') zeros.push_back(i);
        int Z = zeros.size();
        const int K = 200;
        long long ans = 0;
        for (int l = 0; l < n; ++l) {
            int pos = lower_bound(zeros.begin(), zeros.end(), l) - zeros.begin();
            int r_left = l;
            int r_right = (pos < Z) ? zeros[pos] - 1 : n - 1;
            if (r_left <= r_right) ans += (r_right - r_left + 1);
            for (int k = 1; k <= K; ++k) {
                if (pos + k - 1 >= Z) break;
                r_left = zeros[pos + k - 1];
                r_right = (pos + k < Z) ? zeros[pos + k] - 1 : n - 1;
                int need = k * k;
                int lo = r_left, hi = r_right, res = r_right + 1;
                while (lo <= hi) {
                    int mid = (lo + hi) >> 1;
                    int ones = pref[mid + 1] - pref[l];
                    if (ones >= need) { res = mid; hi = mid - 1; }
                    else lo = mid + 1;
                }
                if (res <= r_right) ans += (r_right - res + 1);
            }
        }
        return (int)ans;
    }
};
