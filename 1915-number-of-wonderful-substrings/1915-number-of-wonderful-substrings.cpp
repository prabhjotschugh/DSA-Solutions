class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long result = 0;
        int bitmask = 0;
        vector<int> bitmaskCount(1024, 0);
        bitmaskCount[0] = 1;
        
        for (char c : word) {
            bitmask ^= 1 << (c - 'a');
            result += bitmaskCount[bitmask];
            for (int i = 0; i < 10; ++i) {
                int targetBitmask = bitmask ^ (1 << i);
                result += bitmaskCount[targetBitmask];
            }
            bitmaskCount[bitmask]++;
        }
        
        return result;
    }
};