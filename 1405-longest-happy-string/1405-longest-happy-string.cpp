class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string s = "";
        priority_queue<pair<int, char>> pq;
        if (a > 0)
            pq.push({a, 'a'});
        if (b > 0)
            pq.push({b, 'b'});
        if (c > 0)
            pq.push({c, 'c'});

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int freq = it.first;
            char ch = it.second;
            if (s.length() >= 2 && s[s.length() - 1] == ch &&
                s[s.length() - 2] == ch) {
                if (pq.empty()) {
                    break;
                }
                auto nextit = pq.top();
                pq.pop();
                int nextChFreq = nextit.first;
                char nextCh = nextit.second;
                s.push_back(nextCh);
                nextChFreq--;
                if (nextChFreq > 0)
                    pq.push({nextChFreq, nextCh});
            } else {
                s.push_back(ch);
                freq--;
            }
            if (freq > 0)
                pq.push({freq, ch});
        }
        return s;
    }
};