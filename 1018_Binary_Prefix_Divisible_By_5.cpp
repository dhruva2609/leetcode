class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> answer;
        answer.reserve(nums.size());
        int remainder = 0;

        for (int bit : nums) {
            remainder = (remainder * 2 + bit) % 5;
            answer.push_back(remainder == 0);
        }

        return answer;
    }
};
