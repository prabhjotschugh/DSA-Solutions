class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        for(char c: s)
            freq[c-'a']++;
        set<int> freq_seen;
        int ans=0;
        for(int i=0; i<26; i++){
            int f=freq[i];
            if (f==0) continue;
            while(freq_seen.count(f) && f>0){
                f--;
                ans++;
            }
            if (f>0) freq_seen.insert(f);
        }
        return ans;
    }
};