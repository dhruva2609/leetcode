class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int MAX_N = 100;
        vector<int> counts(MAX_N, 0);

        for (int num : nums) {
            counts[num]++;
        }

        vector<int> result;
        for (int i = 0; i < MAX_N; ++i) {
            if (counts[i] == 2) {
                result.push_back(i);
                if (result.size() == 2) {
                    break;
                }
            }
        }

        return result;
    }
};
