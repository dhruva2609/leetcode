class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drunkBottles = 0;
        int emptyBottles = 0;

        while (numBottles > 0) {
            drunkBottles += numBottles;
            emptyBottles += numBottles;
            numBottles = 0;

            numBottles = emptyBottles / numExchange;
            emptyBottles = emptyBottles % numExchange;
        }

        return drunkBottles;
    }
};
