class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int totalBeams = 0;
        int prevDeviceCount = 0;

        for (const string& row : bank) {
            int currentDeviceCount = count(row.begin(), row.end(), '1');

            if (currentDeviceCount == 0) {
                continue;
            }

            if (prevDeviceCount > 0) {
                totalBeams += prevDeviceCount * currentDeviceCount;
            }

            prevDeviceCount = currentDeviceCount;
        }

        return totalBeams;
    }
};
