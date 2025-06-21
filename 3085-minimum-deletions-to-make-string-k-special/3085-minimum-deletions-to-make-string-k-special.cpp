class Solution {
public:
    static void print(auto& c){
        for(int x:c)
        if (x>0) cout<<x<<", ";
        cout<<endl;
    }
    static int greedy(int* freq, int start, int minF, int k){
        int rm=0;
        for(int i=start; i<26; i++){
            const int x=freq[i];
            rm+=(x<minF)?x:0;
            rm+=(x>minF+k)?x-minF-k:0;
        }
        return rm;
    }
    static int minimumDeletions(string& word, int k) {
        int freq[26]={0}, sz=0;
        const int  n=word.size();
        bitset<26> seen=0;
        for(char c: word){
            int i=c-'a';
            seen[i]=1;
            freq[i]++;
        } 
        sz=seen.count();
        sort(freq, freq+26);
        int len=0, minF=freq[26-sz];
        int ans=n, maxF=freq[25];
        for(int f=minF; f<=maxF; f++){
            ans=min(ans, greedy(freq, 26-sz, f, k));
        }
        return ans;
    }
};