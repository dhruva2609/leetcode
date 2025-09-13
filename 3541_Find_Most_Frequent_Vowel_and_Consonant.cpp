#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxFreqSum(string s) {
        int freq[26] = {0};
        for (char c : s) freq[c - 'a']++;

        int maxVowel = 0, maxConsonant = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) continue;
            char c = 'a' + i;
            if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
                maxVowel = max(maxVowel, freq[i]);
            else
                maxConsonant = max(maxConsonant, freq[i]);
        }
        return maxVowel + maxConsonant;
    }
};
