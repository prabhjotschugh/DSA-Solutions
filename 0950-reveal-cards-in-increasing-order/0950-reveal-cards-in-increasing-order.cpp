class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.rbegin(), deck.rend());
        int n=deck.size();
        deque<int> reveal={deck[0]};
        for(int i=1; i<n; i++){
            int back=reveal.back();
            reveal.pop_back();
            reveal.push_front(back);
            reveal.push_front(deck[i]);
        }
        return vector<int>(reveal.begin(), reveal.end());
    }
};