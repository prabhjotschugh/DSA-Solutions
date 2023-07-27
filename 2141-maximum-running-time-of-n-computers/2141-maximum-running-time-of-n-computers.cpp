class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        int m=batteries.size();
        int min_power=*min_element(batteries.begin(), batteries.end());
        if (m==n) return min_power;
        long long left=min_power;
        long long right=accumulate(batteries.begin(), batteries.end(), 0LL)/n;
        long long mid;
        while(left<right){
            mid=(right+left+1)/2;
            long long reserve=0;
            for (int x: batteries)
                reserve+=min((long long)x, mid);
            if (reserve>=mid*n)
                left=mid;
            else
                right=mid-1;
        }
        return left;
    }
};