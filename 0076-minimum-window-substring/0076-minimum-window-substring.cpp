class Solution {
public:
    string minWindow(string s, string t) {
        int i=0;
        int j=0;
        int ns=s.length();
        int nt=t.length();
        int requirement=nt;
        int len=(int)1e8, head=0;
        vector<int> freq(128, 0);
        for(int i=0;i<nt;i++){
            freq[t[i]]++;
        }
        
        while(j<ns){
            if(freq[s[j++]]-- > 0){
                requirement--;
            }
            
            while(requirement == 0){
                if(len > j-i){
                    len=j-i;
                    head=i;
                }
                
                if(freq[s[i++]]++ == 0){
                    requirement++;
                }
            }
        }
        return (len==(int)1e8) ? "" : s.substr(head, len);
    }
};