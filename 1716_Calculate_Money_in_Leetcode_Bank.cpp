class Solution {
public:
    int totalMoney(int n) {
        int num_weeks = n / 7;
        int remaining_days = n % 7;

        int total = 0;

        total = (num_weeks * (56 + 7 * (num_weeks - 1))) / 2;

        int start_of_partial_week = num_weeks + 1;

        for (int day = 0; day < remaining_days; ++day) {
            total += start_of_partial_week + day;
        }

        return total;
    }
};
