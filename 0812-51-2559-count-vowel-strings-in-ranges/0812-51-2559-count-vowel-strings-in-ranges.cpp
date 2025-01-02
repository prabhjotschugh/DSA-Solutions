class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> prefix, res;
        int count = 0;

        auto isVowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };

        for (auto& word : words) {
            if (isVowel(word[0]) && isVowel(word.back())) {
                count++;
            }
            prefix.push_back(count);
        }

        for (auto query : queries) {
            int l = query[0], r = query[1];
            if (l == 0) {
                res.push_back(prefix[r]);
            } else {
                res.push_back(prefix[r] - prefix[l - 1]);
            }
        }

        return res;
    }
};