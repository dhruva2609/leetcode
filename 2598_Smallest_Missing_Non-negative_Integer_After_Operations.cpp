class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> counts(value, 0);

        for (int num : nums) {
            int rem = (num % value + value) % value;
            counts[rem]++;
        }

        int mex = 0;
        while (true) {
            int rem = mex % value;

            if (counts[rem] > 0) {
                counts[rem]--;
                mex++;
            } else {
                break;
            }
        }

        return mex;
    }
};
