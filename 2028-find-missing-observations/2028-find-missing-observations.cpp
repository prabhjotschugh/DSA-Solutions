class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> ans;
        int m=rolls.size();
        int a=(n+m)*mean;
        int sum=0;
        for(auto num:rolls){
            sum+=num;
        }
        int target=a-sum;
        if(target<=0 || n>target || target>6*n){
            return ans;
        }
        cout<<target<<endl;
        for(int i=0;i<n;i++){
            
            for(int j=6;j>=1;j--){
                 int local=target;
                local-=j;
                if(local>=n-1-i){
                    target=target-j;
                    ans.push_back(j);
                    break;
                }
            }

        }
       return ans;
    }
};