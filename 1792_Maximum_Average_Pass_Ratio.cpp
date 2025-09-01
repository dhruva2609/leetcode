#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto gain = [](int p, int t) {
            return (double)(p + 1) / (t + 1) - (double)p / t;
        };

        // max-heap: (gain, pass, total)
        priority_queue<pair<double, pair<int,int>>> pq;

        for (auto &c : classes) {
            int p = c[0], t = c[1];
            pq.push({gain(p, t), {p, t}});
        }

        while (extraStudents--) {
            auto top = pq.top(); pq.pop();
            int p = top.second.first;
            int t = top.second.second;
            p++; t++;
            pq.push({gain(p, t), {p, t}});
        }

        double totalRatio = 0.0;
        while (!pq.empty()) {
            auto top = pq.top(); pq.pop();
            int p = top.second.first;
            int t = top.second.second;
            totalRatio += (double)p / t;
        }

        return totalRatio / classes.size();
    }
};
