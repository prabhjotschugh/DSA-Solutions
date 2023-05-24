class Solution {
public:
    string minWindow(string s, string t) {
        int ns = s.length();
        int nt = t.length();
        
        int head = 0;
        int i=0;
        int j=0;
        int req = nt;
        int len=INT_MAX;
        vector<int> freq(128, 0);
        for(int i=0;i<nt;i++){
            freq[t[i]]++;
        }
        while(j<ns){
            if(freq[s[j++]]-- > 0){
                req--;
            }
            
            while(req == 0){
                if(j-i < len){
                    len = j-i;
                    head=i;
                }
                
                if(freq[s[i++]]++ == 0){
                    req++;
                }
            }
        }
        return len==INT_MAX ? "" : s.substr(head, len);
    }
};