class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int n = nums.size();

        if (n == 0) {
            return result;
        }

        for (int i = 0; i < n; ) {
            long long start = nums[i];
            int j = i;

            while (j + 1 < n && (long long)nums[j + 1] == (long long)nums[j] + 1) {
                j++;
            }

            int end = nums[j];

            if (start == end) {
                result.push_back(to_string(start));
            } else {
                result.push_back(to_string(start) + "->" + to_string(end));
            }

            i = j + 1;
        }

        return result;
    }
};
