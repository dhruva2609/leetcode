#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        set<int> uniqueNumbers;
        int n = digits.size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j == i) continue;
                for (int k = 0; k < n; ++k) {
                    if (k == i || k == j) continue;

                    int a = digits[i];
                    int b = digits[j];
                    int c = digits[k];

                    if (a != 0 && c % 2 == 0) {
                        int num = 100 * a + 10 * b + c;
                        uniqueNumbers.insert(num);
                    }
                }
            }
        }

        return uniqueNumbers.size();
    }
};
