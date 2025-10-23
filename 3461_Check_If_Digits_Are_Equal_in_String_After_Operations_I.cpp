class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.length() > 2) {
            string next_s = "";

            for (int i = 0; i < s.length() - 1; ++i) {
                int digit1 = s[i] - '0';
                int digit2 = s[i+1] - '0';

                int new_digit = (digit1 + digit2) % 10;

                next_s += to_string(new_digit);
            }

            s = next_s;
        }

        return s[0] == s[1];
    }
};
