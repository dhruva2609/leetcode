class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        if (colors.empty()) {
            return 0;
        }

        int n = colors.length();
        int min_time = 0;

        int current_max_time = neededTime[0];
        int current_sum_time = neededTime[0];

        for (int i = 1; i < n; ++i) {
            if (colors[i] == colors[i - 1]) {
                current_sum_time += neededTime[i];
                current_max_time = max(current_max_time, neededTime[i]);
            } else {
                min_time += (current_sum_time - current_max_time);

                current_sum_time = neededTime[i];
                current_max_time = neededTime[i];
            }
        }

        min_time += (current_sum_time - current_max_time);

        return min_time;
    }
};
