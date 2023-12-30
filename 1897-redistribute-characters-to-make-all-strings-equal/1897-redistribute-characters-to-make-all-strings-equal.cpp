class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        vector<int> f(26, 0);
        for (const string& word : words) {
            for (char c : word) {
                f[c - 'a']++;
            }
        }
        for (int x : f) {
            if (x % n != 0) {
                return false;
            }
        }
        return true;
    }
};