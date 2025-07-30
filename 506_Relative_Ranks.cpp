#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<pair<int, int>> scoreIndex;
        for (int i = 0; i < n; i++) {
            scoreIndex.push_back({score[i], i});
        }

        sort(scoreIndex.begin(), scoreIndex.end(), [](auto &a, auto &b) {
            return a.first > b.first;
        });

        vector<string> result(n);
        for (int i = 0; i < n; i++) {
            if (i == 0) result[scoreIndex[i].second] = "Gold Medal";
            else if (i == 1) result[scoreIndex[i].second] = "Silver Medal";
            else if (i == 2) result[scoreIndex[i].second] = "Bronze Medal";
            else result[scoreIndex[i].second] = to_string(i + 1);
        }

        return result;
    }
};

