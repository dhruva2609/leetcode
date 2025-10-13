class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        if (words.empty()) {
            return {};
        }

        vector<string> ans;
        ans.push_back(words[0]);

        for (int i = 1; i < words.size(); ++i) {
            string current_sorted = words[i];
            sort(current_sorted.begin(), current_sorted.end());

            string last_ans_sorted = ans.back();
            sort(last_ans_sorted.begin(), last_ans_sorted.end());

            if (current_sorted != last_ans_sorted) {
                ans.push_back(words[i]);
            }
        }

        return ans;
    }
};
