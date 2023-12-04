class Solution {
private:
    int isvalid(string s, unordered_map<char, int>map) {
        int n = s.size();
        for (auto i : s) {
            auto it = map.find(i);
            if (it != map.end() && it->second > 0) {
                map[i]--;
            } else {
                return 0;
            }
        }
        return n;
    }

public:
    int countCharacters(vector<string>& words, string chars) {
        int ans = 0;
        unordered_map<char, int> mp;
        for (auto i : chars) {
            mp[i]++;
        }
        for (auto i : words) {
            ans += isvalid(i, mp);
        }
        return ans;
    }
};