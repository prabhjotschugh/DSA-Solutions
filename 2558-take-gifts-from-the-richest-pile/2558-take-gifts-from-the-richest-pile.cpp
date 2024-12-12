class Solution {
public:
    long long pickGifts(vector<int>& g, int k) {
        make_heap(g.begin(), g.end());
        for (int i = 0, x = INT_MAX; i < k && x > 1; i++) {
            pop_heap(g.begin(), g.end());
            x = g.back();
            g.back() = sqrt(g.back());
            push_heap(g.begin(), g.end());
        }
        return accumulate(g.begin(), g.end(), 0LL);
    }
};