class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        vector<pair<int,int>> v;
        pair<int,int> prev={0,0};
        int maxi=0;
        for(int i = 0; i<answerKey.length(); i++){
            if(answerKey[i]=='T'){
                prev.first++;
                v.push_back(prev);
            }
            else{
                prev.second++;
                v.push_back(prev);
            }
            if(min(prev.first,prev.second)<=k)maxi=i+1;
        }
        prev={0,0};
        int i=0;
        int index=0;
        
        while(i<v.size()){
            if(min(v[i].first-prev.first,v[i].second-prev.second)<=k){
                i++;
            }
            else{
                maxi=max(maxi,i-index);
                prev=v[index];
                index++;
            }
        }
        
        return max(maxi,i-index);
    }
};