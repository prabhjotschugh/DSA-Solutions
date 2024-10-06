class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        vector<string> w1 = split(s1), w2 = split(s2);
        int i{0}, j{0}, n1 = w1.size(), n2 = w2.size();
        while (i < n1 && i < n2 && w1[i] == w2[i]) ++i;
        while (j < n1 - i && j < n2 - i && w1[n1 - 1 - j] == w2[n2 - 1 - j]) ++j;
        return i + j == n1 || i + j == n2;
    }
private:
    vector<string> split(const string& s) {
        istringstream ss(s);
        return {istream_iterator<string>(ss), istream_iterator<string>()};
    }
};