class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int count1[26] = {0};
        for(int i = 0; i < s1.size(); i++) count1[s1[i] - 'a']++;
        for(int i = 0; i < s2.size(); i++) {
            bool flag = true;
            string str = s2.substr(i, s1.size());       
            int count2[26] = {0};
            for(int j = 0; j < str.size(); j++) count2[str[j] - 'a']++;
            for(int idx = 0; idx < 26; idx++) {
                if(count1[idx] != count2[idx]) {
                    flag = false;
                    break;
                }
            }    
            if(flag) return true;       
        }
        return false;
    }
};