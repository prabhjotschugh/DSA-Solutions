class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int mp[82];  
        memset(mp, -1, sizeof(mp));
        int ans = -1;

        for (int num : nums) {
            int sumDigits = 0, temp = num;
            while (temp) sumDigits += temp % 10, temp /= 10;

            if (mp[sumDigits] != -1)
                ans = max(ans, num + mp[sumDigits]);

            mp[sumDigits] = max(mp[sumDigits], num);
        }

        return ans;
    }
};