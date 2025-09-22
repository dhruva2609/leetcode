#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }

        int maxFreq = 0;
        for (const auto& pair : freqMap) {
            if (pair.second > maxFreq) {
                maxFreq = pair.second;
            }
        }

        int count = 0;
        for (const auto& pair : freqMap) {
            if (pair.second == maxFreq) {
                count += maxFreq;
            }
        }

        return count;
    }
};
