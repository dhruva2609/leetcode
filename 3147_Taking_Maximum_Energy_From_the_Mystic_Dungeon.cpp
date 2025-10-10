class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int max_energy = -200000000;

        for (int i = n - 1; i >= 0; --i) {
            if (i + k < n) {
                energy[i] += energy[i + k];
            }
            max_energy = max(max_energy, energy[i]);
        }

        return max_energy;
    }
};
