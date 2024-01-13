class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> m1(26, 0), m2(26, 0);
        for(auto c : s) 
            m1[c-'a']++;
        
        for(auto c : t) 
            m2[c-'a']++;
        
        int ans = 0;
        for(int i = 0;i < 26;i++){
            if(m1[i] > m2[i]) 
                ans += m1[i] - m2[i]; 
        }
        return ans;
    }
};