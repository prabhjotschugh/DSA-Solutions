class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int maxDistance = -1;
        for (int left = 0; left < s.size(); left++) {
            for (int right = left + 1; right < s.size(); right++) {
                if (s[left] == s[right]) {
                    maxDistance = max(maxDistance, right - left - 1);
                }
            }
        }

        return maxDistance;    
    }
};