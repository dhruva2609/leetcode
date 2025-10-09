class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }

        int minPrice = prices[0];
        int maxProfit = 0;

        for (size_t i = 1; i < prices.size(); ++i) {
            int currentProfit = prices[i] - minPrice;

            maxProfit = max(maxProfit, currentProfit);

            minPrice = min(minPrice, prices[i]);
        }

        return maxProfit;
    }
};
