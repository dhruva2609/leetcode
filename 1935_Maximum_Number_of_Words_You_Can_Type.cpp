class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());
        int wordCount = 0;
        bool brokenFound = false;

        for (int i = 0; i <= text.size(); i++) {
            if (i < text.size() && text[i] != ' ') {
                if (broken.count(text[i])) {
                    brokenFound = true;
                }
            } else {

                if (!brokenFound) {
                    wordCount++;
                }
                brokenFound = false;
            }
        }

        return wordCount;
    }
};
