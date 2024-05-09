class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(), happiness.rend());

        long long total = 0;
        for (int turn = 0; turn < k; ++turn) {
            long long current = max(happiness[turn] - turn, 0);
            total+= current;
        }
        return total;
    }
};