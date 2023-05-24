class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0;
        int j=0;
        int distinct=0;
        int n=fruits.size();
        int maxi=0;
        
        unordered_map<int,int> freq;
        while(j<n){
            if(freq[fruits[j++]]++ == 0){
                distinct++;
            }
            
            if(distinct <= 2){
                maxi = max(maxi, j-i);
            }else if(distinct > 2){
                if(freq[fruits[i++]]-- == 1){
                    distinct--;
                }
            }
        }
        return maxi;
    }
};