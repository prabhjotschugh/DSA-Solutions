class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> leastNeighbour(n, INT_MAX);
        for (auto & i : edges) {
            leastNeighbour[i[0]] = min(i[1], leastNeighbour[i[0]]);
            leastNeighbour[i[1]] = min(i[0], leastNeighbour[i[1]]);

        }
        vector<bool>mustVisit(n ,false);
        int j = 0;
        for (int i = n - 1; i > 0; --i) {
            if(hasApple[i]){
                j = i;
                while(not mustVisit[j] && j != 0){
                    mustVisit[j] = true;
                    j = leastNeighbour[j];
                }
            }
        }
        int counter = 0;
        for (auto i : mustVisit) {
            counter += int(i);
        }
        return  2*counter;
    }
};