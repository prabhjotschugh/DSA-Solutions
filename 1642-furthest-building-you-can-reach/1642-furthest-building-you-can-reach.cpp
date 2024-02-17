class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        int usedBrick = 0;
        priority_queue<int, vector<int>, greater<int>> gapLadder;
        int result = 0;
        for (int i = 1; i < n; i++) {
            if (heights[i - 1] >= heights[i]) {
                result++;
            }
            else {
                int gap = heights[i] - heights[i - 1];
                gapLadder.push(gap);
                if (gapLadder.size() > ladders) {
                    usedBrick += gapLadder.top();
                    gapLadder.pop();
                }
                if ((usedBrick > bricks) && (gapLadder.size() == ladders))
                    break;
                
                result++;
            }
        }
        return result;

    }
};