class Solution {
public:
    int minSwaps(vector<int>& v) {
        int ones = 0;
        for (auto& x : v) {
            if (x == 1) {
                ones++;
            }
        }
        if (ones == 0 || ones == 1) {
            return 0;
        }
        
        int n = v.size();
        int windowSum = accumulate(v.begin(), v.begin() + ones, 0);
        int maxOnesInWindow = windowSum;
        for (int i = 0; i < n; ++i) {
            int end = (i + ones) % n; 
            int start = i;
            
            windowSum -= v[start];
            windowSum += v[end];   
            maxOnesInWindow = max(maxOnesInWindow, windowSum);
        }
        return ones - maxOnesInWindow;
    }
};