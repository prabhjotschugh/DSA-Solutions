class Solution {
public:
    long long minEnd(int n, int x) {
        long long num = x;

        for(int i = 1 ; i <  n ; i++){     
            num = (num + 1) | x;
        }

        return num;
    }
};