class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
    sort(tokens.begin(), tokens.end());
    int s = 0;
    int maxi = 0;
    int l = 0, r = tokens.size() - 1;
    while (l <= r) {
        if (power >= tokens[l]) {
            power -= tokens[l];
            s++;
            l++;
            maxi = max(maxi, s);
        }
        else if (s > 0) {
            power += tokens[r];
            s--;
            r--;
        }
        else {
            break;
        }
    }
    return maxi;
}

};