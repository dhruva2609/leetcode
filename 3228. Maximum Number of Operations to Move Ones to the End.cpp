class Solution {
public:
    int maxOperations(string s) {
        int n = s.length();
        int operations = 0;
        int ones_count = 0;

        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                ones_count++;
            } else {
                if (i > 0 && s[i-1] == '1') {
                    operations += ones_count;
                }

                while (i + 1 < n && s[i + 1] == '0') {
                    i++;
                }
            }
        }

        return operations;
    }
};
