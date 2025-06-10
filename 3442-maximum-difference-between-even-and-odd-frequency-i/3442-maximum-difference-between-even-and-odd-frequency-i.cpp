#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        int odd = 0;
        int even = s.length();
        for (int n : freq) {
            if (n % 2 == 1) {
                odd = max(odd, n);
            } else if (n != 0) {
                even = min(even, n);
            }
        }

        return odd - even;
    }
};